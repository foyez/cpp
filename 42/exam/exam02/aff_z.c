#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc; // suppresses compiler warnings about unused variables
	(void)argv;
	write(1, "z\n", 2);
	return (0);
}
