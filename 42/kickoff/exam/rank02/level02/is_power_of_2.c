int	    is_power_of_2(unsigned int n)
{
	unsigned int prod = 1;

	while (prod <= n)
	{
		if (prod == n)
			return (1);
		prod *= 2;
	}
	return (0);
}


#include <stdio.h>
int main()
{
	printf("%d", is_power_of_2(16));
}
