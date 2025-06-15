#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char search, char replace)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	search;
	char	replace;

	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		str = argv[1];
		search = argv[2][0];
		replace = argv[3][0];
		search_and_replace(str, search, replace);
	}
	ft_putchar('\n');
	return (0);
}
