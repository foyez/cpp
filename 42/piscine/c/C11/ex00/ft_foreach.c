void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

#include <stdio.h>

void	ft_putnbr(int nb)
{
	printf("%d\n", nb);
}

int	main(void)
{
	int	tab[3] = {1, 2, 3};
	int	length;

	length = 3;
	ft_foreach(tab, length, &ft_putnbr);
	return (0);
}
