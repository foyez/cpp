#include <stdlib.h>

// memory leak: allocated memory is not freed
// heap buffer overflow: writing beyond allocated memory
int	main(void)
{
	int *arr;

	arr = malloc(5 * sizeof(int));
	for (int i = 0; i <= 5; i++)
	{
		arr[i] = i;
	}

	return (0);
}
