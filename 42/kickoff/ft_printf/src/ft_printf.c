#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int parse_nbr(char *str)
{
	int nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return nbr;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int ft_printf(const char *format, ...)
{
	va_list args;
	int left_align;
	int width;
	int precision;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			// Handle '-'
			if (*format == '-')
			{
				left_align = 1;
				format++;
			}
			// Get width
			while (*format >= '0' && *format <= '9')
			{
				width = width * 10 + (*format - '0');
				format++;
			}
			// Get precision
			if (*format == '.')
			{
				format++;
				precision = 0;
				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					format++;
				}
			}
			// Handle %s
			if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				ft_print_str(str, left_align, width, precision);
			}
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return 0;
}

int main()
{
	ft_printf("[%10.3s]\n", "hello");
	return 0;
}
