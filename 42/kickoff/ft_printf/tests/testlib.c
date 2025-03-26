#include "../include/ft_printf.h"

int	main(void)
{
	// printf("%+u", 42);
	ft_printf("[%+10.3u]\n", 42);
	ft_printf("[%-10.3d]\n", -42);
	printf("[%010s]\n", "Hello");
	return (0);
}
