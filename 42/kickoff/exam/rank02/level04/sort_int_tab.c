void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int min_idx;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[min_idx] > tab[j])
				min_idx = j;
			j++;
		}
		tmp = tab[min_idx];
		tab[min_idx] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	arr[5] = {3, 4, 2, 7, 1};

	sort_int_tab(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return (0);
}
