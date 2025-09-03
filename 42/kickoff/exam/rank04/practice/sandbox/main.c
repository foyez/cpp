#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

void nice_fn() {}

void bad_exit_code_2() {
	exit(2);
}

int main()
{
	int res;

	printf("Nice func:\n");
	res = sandbox(nice_fn, 2, true);
	printf("Result: %d\n", res);

	printf("Bad exit code 2:\n");
	res = sandbox(bad_exit_code_2, 2, true);
	printf("Result: %d\n", res);

	return 0;
}
