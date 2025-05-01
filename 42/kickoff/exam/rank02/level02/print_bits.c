#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		// if i == 8 and octet == 5
		// if i = 7, (5 >> 7) & 1 => (00000101 >> 7) & 1 => 00000000 & 00000001 => 0
		// ...
		// if i = 2, (5 >> 2) & 1 => (00000101 >> 2) & 1 => 00000001 & 00000001 => 1
		// if i = 1, (5 >> 1) & 1 => (00000101 >> 1) & 1 => 00000010 & 00000001 => 0
		// if i = 0, (5 >> 0) & 1 => (00000101 >> 0) & 1 => 00000101 & 00000001 => 1
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

/*
	If you shift a value by more bits than the number of bits in its type,
	the behavior is undefined for signed integers,
	but for unsigned integers, the result is typically 0.
*/
/*
	Bit-width:
	int or unsigned int -> 32 bits
	char or unsigned char -> 8 bits
	long -> 32 bits
	long long -> 64 bits
*/
/*
	Safe Rule to Follow:
	Never shift by a value ≥ the number of bits in the type.
*/
/*
	(3 >> 1) & 1 => (00000011 >> 1) & 1 => 00000001 & 1 => 00000001 => 1
	(3 >> 1) && 1 => (00000011 >> 1) & 1 => 00000001 && 1 => true => 1
*/
/*
	Usecase of & (bitwise AND) and && (logical AND):
	& → looks at individual bits
	&& → checks if values are non-zero (true/false)
*/
/*
	How & and && works:
	1 & 2 = 0 // last bits: 01 & 10 = 00
	1 && 2 = 0 // both non-zero -> true
*/

int	main(void)
{
	unsigned char	octet;

	octet = 5;
	print_bits(octet);
	return (0);
}
