#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int print_str(const char *s)
{
	int i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_putchar(s[i++]);
	return i;
}

int print_num(int n)
{
	int count = 0;
	if (n == -2147483648)
		return print_str("-2147483648");
	if (n < 0)
	{
		count += ft_putchar('-');
		count += print_num(-n);
	}
	else
	{
		if (n > 9)
			count += print_num(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return count;
}

int print_hex(unsigned int n)
{
	int count = 0;
	char *base = "0123456789abcdef";
	if (n > 15)
		count += print_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return count;
}

int handle_format(char c, va_list *args)
{
	if (c == 's')
		return print_str(va_arg(*args, char *));
	if (c == 'd')
		return print_num(va_arg(*args, int));
	if (c == 'x')
		return print_hex(va_arg(*args, unsigned int));
	return ft_putchar(c);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += handle_format(*format, &args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return count;
}

int main(void)
{
	// ft_printf("Hello %s\n", "toto");
	ft_printf("Hello %s, your score is %d, hex: %x\n", "Foyez", 100, 100);
	ft_printf("Magic %s is %d", "number", 42);
	// ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	return (0);
}
