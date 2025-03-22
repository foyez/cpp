#include "ft_printf.h"

int ft_print_str(char *str, int left_align, int width, int precision)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (left_align)
	{
		write(1, str, len);
		while (len < width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	else
	{
		while (len < width)
		{
			ft_putchar(' ');
			len++;
		}
		write(1, str, len);
	}
	return 0;
}
