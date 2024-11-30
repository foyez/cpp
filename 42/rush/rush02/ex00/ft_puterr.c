#include <unistd.h>

void	ft_puterr(void)
{
	write(1, "Error\n", 6);
}

void	ft_putdicterr(void)
{
	write(1, "Dict Error\n", 11);
}
