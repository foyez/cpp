#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose);

void nice_fn()
{
	return;
}

void bad_fn_exit_code()
{
	// terminates with error code
	exit(1);
}

void bad_fn_segfault()
{
	int *ptr = NULL;
	*ptr = 42;
}

void bad_fn_timeout()
{
	while (1) {}
}

void bad_fn_abort()
{
	abort();
}

int main()
{
	int res;

	printf("Nice function:\n");
	res = sandbox(nice_fn, 5, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (segfault):\n");
	res = sandbox(bad_fn_segfault, 5, true);
	printf("Result: %d\n\n", res);

	printf("Bad function (timeout):\n");
	res = sandbox(bad_fn_timeout, 5, true);
	printf("Result: %d\n\n", res);

	printf("Bad function:\n");
	res = sandbox(bad_fn_abort, 5, true);
	printf("Result: %d\n\n", res);

	return 0;
}
