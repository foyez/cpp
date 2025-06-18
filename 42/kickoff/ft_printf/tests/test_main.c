#include "../include/ft_printf.h"

int main(void)
{
	// ft_printf("Hello %s\n", "toto");
	ft_printf("Hello %s, your score is %d, hex: %x\n", "Foyez", 100, 100);
	ft_printf("Magic %s is %d", "number", 42);
	// ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	return (0);
}
