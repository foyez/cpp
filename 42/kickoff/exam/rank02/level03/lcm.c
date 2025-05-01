unsigned int gcd(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	return (a * b) / gcd(a, b);
}

#include <stdio.h>

int main()
{
	printf("%d\n", lcm(12, 18));
	return 0;
}
