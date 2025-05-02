#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rotone(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == 'Z' || s[i] == 'z')
			s[i] -= 25;
		else if ((s[i] >= 'A' && s[i] <= 'Y') || (s[i] >= 'a' && s[i] <= 'y'))
			s[i]++;
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}
