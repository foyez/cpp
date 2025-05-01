#include<unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void hidenp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
			s1++;
		s2++;
	}
	if (!*s1)
		ft_putchar('1');
	else
		ft_putchar('0');
}

int main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
