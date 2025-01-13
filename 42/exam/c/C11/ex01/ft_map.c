#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*updated_tab;

	updated_tab = (int *)malloc(sizeof(int) * length);
	if (!updated_tab)
		return (NULL);
	i = -1;
	while (++i < length)
	{
		updated_tab[i] = f(tab[i]);
	}
	return (updated_tab);
}

int	ft_square(int n)
{
	return (n * n);
}

#include <stdio.h>

int	main(void)
{
	int	tab[3] = {1, 2, 3};
	int	length;
	int	*updated_tab;

	length = 3;
	updated_tab = ft_map(tab, length, &ft_square);
	for (int i = 0; i < length; i++)
		printf("%d\n", updated_tab[i]);
	free(updated_tab);
	return (0);
}
