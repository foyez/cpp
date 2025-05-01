#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	int				bit;
	unsigned char	res;

	res = 0;
	i = 8;
	while (i--)
	{
		res |= (octet >> i);
		res <<= 1;
	}
	return (res);
}

int	main(void)
{
	printf("%d\n", reverse_bits(65));
	return (0);
}
