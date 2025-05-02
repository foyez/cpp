int max(int *tab, unsigned int len)
{
	int res = 0;
	int i = 0;

	if (len <= 0)
		return (res);
	while (i < len)
	{
		if (tab[i] > res)
			res = tab[i];
		i++;
	}
	return (res);
}


#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 5));
}
