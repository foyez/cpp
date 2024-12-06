#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_last_word(char *str)
{
	int	i;
	int	n;

	n = ft_strlen(str);
	i = n - 1;
	while (ft_is_whitespace(str[i]))
		i--;
	while (i > 0)
	{
		if (ft_is_whitespace(str[i]))
		{
			i++;
			break ;
		}
		i--;
	}
	while (str[i] != '\0' && !ft_is_whitespace(str[i]))
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
