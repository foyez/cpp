#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

static volatile sig_atomic_t g_timeout = 0;
static volatile sig_atomic_t g_child_pid = -1;

static void handle_alarm(int signo) {
	(void)signo;
	pid_t pid = (pid_t)g_child_pid;
	if (pid > 0) {
		if (kill(pid, SIGKILL) == 0)
			g_timeout = 1;
	}
}

static int wait_child(pid_t pid, int *wstatus) {
	int ret;

	while (1) {
		ret = waitpid(pid, wstatus, WUNTRACED);
		if (ret >= 0)
			return 0;
		if (errno == EINTR)
			continue;
		return -1;
	}
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose) {
	pid_t pid;
	int wstatus;
	int ret;

	pid = fork();
	if (pid == -1)
		return -1;
	if (pid == 0) {
		alarm(0);
		f();
		exit(0);
	}

	g_child_pid = pid;

	struct sigaction sa, sa_old;
	int has_alarm = 0;

	if (timeout > 0) {
		sa.sa_handler = handle_alarm;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGALRM, &sa, &sa_old) == -1) {
			kill(pid, SIGKILL);
			wait_child(pid, &wstatus);
			return -1;
		}
		has_alarm = 1;
		alarm(timeout);
	}

	ret = wait_child(pid, &wstatus);
	if (ret == -1) {
		kill(pid, SIGKILL);
		wait_child(pid, &wstatus);
		if (has_alarm) {
			alarm(0);
			sigaction(SIGALRM, &sa_old, NULL);
		}
		return -1;
	}

	if (WIFSTOPPED(wstatus)) {
		int sig = WSTOPSIG(wstatus);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		kill(pid, SIGKILL);
		wait_child(pid, &wstatus);
		if (has_alarm) {
			alarm(0);
			sigaction(SIGALRM, &sa_old, NULL);
		}
		return 0;
	}

	if (has_alarm) {
		alarm(0);
		sigaction(SIGALRM, &sa_old, NULL);
	}

	if (g_timeout) {
		if (verbose)
			printf("Bad function: time out after %u seconds\n", timeout);
		return 0;
	}

	if (WIFSIGNALED(wstatus)) {
		int sig = WTERMSIG(wstatus);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return 0;
	}
	if (WIFEXITED(wstatus)) {
		int code = WEXITSTATUS(wstatus);
		if (code == 0) {
			if (verbose)
				printf("Nice function!\n");
			return 1;
		}
		if (verbose)
			printf("Bad function: exited with code %d\n", code);
		return 0;
	}
	return -1;
}
