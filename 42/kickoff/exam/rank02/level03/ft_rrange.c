#include <stdlib.h>

int ft_tabs(int n)
{
	return n < 0 ? -n : n;
}

int *ft_rrange(int start, int end)
{
	int size = ft_tabs(end - start) + 1;
	int *range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	int i = -1;
	while (++i < size)
		range[i] = end < start ? end++ : end--;
	return (range);
}

#include <stdio.h>

int main(void)
{
	int *range = ft_rrange(1, 3);
	if (!range)
		return 1;
	for (int i = 0; i < 3; i++)
		printf("%d\n", range[i]);
	free(range);
	return 0;
}
