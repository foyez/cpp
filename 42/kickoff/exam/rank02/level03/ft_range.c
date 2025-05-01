#include <stdlib.h>

int ft_tabs(int n)
{
	if (n < 0)
		return -n;
	return n;
}

int *ft_range(int start, int end)
{
	int size = ft_tabs(end - start) + 1;
	int *range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	int i = -1;
	while (++i < size)
	{
		if (start <= end)
			range[i] = start++;
		else
			range[i] = start--;
	}
	return (range);
}

#include <stdio.h>

int main(void)
{
	int *range = ft_range(1, 3);
	if (!range)
		return 1;
	for (int i = 0; i < 3; i++)
		printf("%d\n", range[i]);
	free(range);
	return 0;
}
