#include <stdarg.h>
#include <unistd.h>

int ft_putchar(int fd, char c)
{
	return write(fd, &c, 1);
}

int print_str(int fd, const char *s)
{
	int i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		if (ft_putchar(fd, s[i++]) == -1)
			return -1;
	}
	return i;
}

int print_num(int fd, int n)
{
	int count = 0, ret;
	if (n == -2147483648)
		return print_str(fd, "-2147483648");
	if (n < 0)
	{
		if ((ret = ft_putchar(fd, '-')) == -1) return -1;
		count += ret;
		if ((ret = print_num(fd, -n)) == -1) return -1;
		count += ret;
	}
	else
	{
		if (n > 9)
		{
			if ((ret = print_num(fd, n / 10)) == -1) return -1;
			count += ret;
		}
		if ((ret = ft_putchar(fd, n % 10 + '0')) == -1) return -1;
		count += ret;
	}
	return count;
}

int print_hex(int fd, unsigned int n)
{
	int count = 0, ret;
	char *base = "0123456789abcdef";
	if (n > 15)
	{
		if ((ret = print_hex(fd, n / 16)) == -1) return -1;
		count += ret;
	}
	if ((ret = ft_putchar(fd, base[n % 16])) == -1) return -1;
	count += ret;
	return count;
}

int handle_format(int fd, char c, va_list *args)
{
	if (c == 's')
		return (print_str(fd, va_arg(*args, char *)));
	if (c == 'd')
		return (print_num(fd, va_arg(*args, int)));
	if (c == 'x')
		return (print_hex(fd, va_arg(*args, unsigned int)));
	return ft_putchar(fd, c);
}

int ft_vdprintf(int fd, const char *format, va_list args)
{
	int		count;
	int		ret;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ret = handle_format(fd, *format, &args);
		}
		else
			ret = ft_putchar(fd, *format);
		if (ret == -1)
			return (-1);
		count += ret;
		format++;
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	int		count;
	va_list args;

	va_start(args, format);
	count = ft_vdprintf(1, format, args);
	va_end(args);
	return (count);
}

int main(void)
{
	// ft_printf("Hello %s\n", "toto");
	ft_printf("Hello %s, your score is %d, hex: %x\n", "Foyez", 100, 100);
	ft_printf("Magic %s is %d", "number", 42);
	// ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	return (0);
}
