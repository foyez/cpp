#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void close_if_open(int *fd) {
  if (*fd != -1) {
    close(*fd);
    *fd = -1;
  }
}

int picoshell(char **cmds[]) {
	int i;
  int ncmds;
  int prev_in;
  int pfd[2];
  int status;
  int children = 0;

  if (!cmds || !cmds[0])
    return 0;

  ncmds = 0;
  while (cmds[ncmds])
    ncmds++;

  prev_in = -1;
  int has_error = 0;
  i = -1;
  while (++i < ncmds) {
    int need_pipe = (i < ncmds - 1);
    if (need_pipe && pipe(pfd) == -1) {
      has_error = 1;
      close_if_open(&prev_in);
      break;
    }

    pid_t pid = fork();
    if (pid == -1) {
      has_error = 1;
      if (need_pipe) {
        close(pfd[0]);
        close(pfd[1]);
      }
      close_if_open(&prev_in);
      break;
    }
    if (pid == 0) {
      if (prev_in != -1) {
        if (dup2(prev_in, STDIN_FILENO) == -1)
          exit(1);
      }
      if (need_pipe) {
        if (dup2(pfd[1], STDOUT_FILENO) == -1)
          exit(1);
      }
      close_if_open(&prev_in);
      if (need_pipe) {
        close(pfd[0]);
        close(pfd[1]);
      }

      execvp(cmds[i][0], cmds[i]);
      exit(1);
    }
    else {
      children++;
      close_if_open(&prev_in);
      if (need_pipe) {
        close(pfd[1]);
        prev_in = pfd[0];
      }
    }
  }
  close_if_open(&prev_in);

  while (children > 0) {
    if (wait(&status) > 0) {
      if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        has_error = 1;
      children--;
    }
    else {
      break;
    }
  }
  return has_error ? 1 : 0;
}
