#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void rotstring(char *s)
{
	int i = 0;
	int j;

	while (s[i] && is_space(s[i]))
		i++;
	j = i;
	while (s[i])
	{
		while (s[i] && !is_space(s[i]))
			i++;
		while (s[i] && is_space(s[i]))
			i++;
		while (s[i] && !is_space(s[i]) && is_space(s[i - 1]))
		{
			while (s[i] && !is_space(s[i]))
			{
				write(1, &s[i], 1);
				i++;
			}
			write(1, " ", 1);
			i++;
		}
	}
	while (s[j] && !is_space(s[j]))
	{
		write(1, &s[j], 1);
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc >= 2)
		rotstring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
