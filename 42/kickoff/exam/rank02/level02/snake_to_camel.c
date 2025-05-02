#include <unistd.h>

int toUpper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return c;
}
int ft_putchar(char c)
{
	return write(1, &c, 1);
}

void snake_to_camel(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '_')
			ft_putchar(toUpper(s[++i]));
		else
			ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	ft_putchar('\n');
	return 0;
}
