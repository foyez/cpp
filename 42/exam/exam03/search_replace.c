#include <unistd.h>

void	search_and_replace(char *str, char search, char replace)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		write(1, &str[i], 1);
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
	write(1, "\n", 1);
	return (0);
}
