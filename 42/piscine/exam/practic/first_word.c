#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_first_word(char *str)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	while (str[i] != '\0' && !ft_is_whitespace(str[i]))
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_first_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
