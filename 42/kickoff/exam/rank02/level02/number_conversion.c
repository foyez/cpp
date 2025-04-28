#include <stdio.h>

void	print_binary(unsigned int num)
{
	int				i;
	unsigned int	bit;

	// int => 4 bytes => 32 bits
	i = 31;
	printf("Binary: ");
	while (i >= 0)
	{
		bit = (num >> i) & 1;
		printf("%d", bit);
		i--;
	}
	printf("\n");
}

// msb (most significant bit) to lsb (least significant bit)
// leftmost bit => msb
// rightmost bit => lsb
int	binary_to_decimal(int bits[], int size)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (i < size)
	{
		// if size == 4
		// if i = 0, (0000 << 1) | 1 => 0000 | 1 => 0001 => 1
		// if i = 1, (0001 << 1) | 0 => 0010 | 0 => 0010 => 2
		// if i = 2, (0010 << 1) | 1 => 0100 | 1 => 0101 => 5
		// if i = 3, (0101 << 1) | 1 => 1010 | 1 => 1011 => 11
		num = (num << 1) | bits[i];
		i++;
	}
	return (num);
}

// xor
void	swap(void)
{
	int	a;
	int	b;

	a = 2;     // 0010
	b = 3;     // 0011
	a = a ^ b; // 0010 ^ 0011 => 0001 => 1
	b = a ^ b; // 0001 ^ 0011 => 0010 => 2
	a = a ^ b; // 0001 ^ 0010 => 0011 => 3
	printf("a = %d, b = %d\n", a, b);
}

// AND
// if the last bit is 1 -> odd
// even numbers always end with 0
// odd numbers always end with 1
int	is_even(int num)
{
	// if num == 4
	// 0100 & 1 => 1 & 1 => 1
	if (num & 1)
		return (0);
	return (1);
}

// multiply or division by powers of two
// multiply by 2: n << 1
// multiply by 4: n << 2
// divide by 2: n >> 1
// divide by 4: n >> 2
void	multiply_divide(void)
{
	int	n;

	n = 5;
	printf("5 * 2 = %d\n", n << 1); // 5 * 2 = 10
	printf("5 / 2 = %d\n", n >> 1); // 5 /2 = 2
}

int	main(void)
{
	unsigned int	n;
	int				bits[] = {1, 0, 1, 1};
	int				decimal;

	n = 23;
	print_binary(n);
	decimal = binary_to_decimal(bits, sizeof(bits) / sizeof(bits[0]));
	printf("Decimal: %d\n", decimal);
	swap();
	printf("%s\n", is_even(4) ? "even" : "odd");
	multiply_divide();
}
