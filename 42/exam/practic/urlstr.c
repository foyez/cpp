#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	urlstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		urlstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
