#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int ft_strlen(char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return (len);
}

void ft_last_word(char *s)
{
	int n = ft_strlen(s);
	int i = n - 1;

	while (is_whitespace(s[i]))
		i--;
	while (i > 0)
	{
		if (is_whitespace(s[i]))
		{
			i++;
			break;
		}
		i--;
	}
	while (s[i] && !is_whitespace(s[i]))
	{
		ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
