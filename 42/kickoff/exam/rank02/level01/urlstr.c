#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void urlstr(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		else if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		urlstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
