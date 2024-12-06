#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'Z' || str[i] == 'z')
		{
			str[i] -= 25;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Y') || (str[i] >= 'a'
				&& str[i] <= 'y'))
		{
			str[i]++;
		}
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rotone(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
