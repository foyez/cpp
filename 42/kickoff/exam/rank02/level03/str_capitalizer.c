#include <unistd.h>

int is_space(char c)
{
	return c == ' ' || c == '\t';
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rstr_capitalizer(char *s)
{
	int i = -1;

	while (s[++i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (i == 0 || is_space(s[i-1])))
			s[i] -= 32;
		ft_putchar(s[i]);
	}
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 1)
		ft_putchar('\n');
	else
	{
		while (++i < argc)
		{
			rstr_capitalizer(argv[i]);
			ft_putchar('\n');
		}
	}
	return (0);
}
