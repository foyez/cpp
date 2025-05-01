#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	expand_str(char *str)
{
	int	space;

	space = 0;
	while (is_space(*str))
		str++;
	while (*str)
	{
		if (is_space(*str))
			space = 1;
		if (!is_space(*str))
		{
			if (space)
				write(1, "   ", 3);
			space = 0;
			ft_putchar(*str);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	ft_putchar('\n');
	return (0);
}
