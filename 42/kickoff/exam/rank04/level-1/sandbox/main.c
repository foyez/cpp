#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose);

void nice_fn()
{
}

void bad_exit_code_2()
{
	// terminates with error code
	exit(2);
}

void bad_segfault()
{
	int *ptr = NULL;
	*ptr = 42;
}

void bad_timeout()
{
	while(1) {}
}

void bad_abort()
{
	// call abort() => SIGABRT
	abort();
}

void bad_timeout_pause()
{
	while(1)
		pause();
}

void bad_stopped()
{
	raise(SIGSTOP);
}

int main()
{
	int res;

	printf("Nice function:\n");
	res = sandbox(nice_fn, 2, true);
	printf("Result: %d\n\n", res);

	printf("Bad function exit code 2:\n");
	res = sandbox(bad_exit_code_2, 2, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (segfault):\n");
	res = sandbox(bad_segfault, 2, true);
	printf("Result: %d\n\n", res);

	printf("Bad function:\n");
	res = sandbox(bad_abort, 2, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (timeout):\n");
	res = sandbox(bad_timeout, 1, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (timeout pause):\n");
	res = sandbox(bad_timeout_pause, 1, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (stopped by signal):\n");
	res = sandbox(bad_stopped, 2, true);
	printf("Result: %d\n\n", res);

	return 0;
}
