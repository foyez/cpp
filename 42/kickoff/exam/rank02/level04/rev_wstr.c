#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void rev_wstr(char *s)
{
	int i = 0;
	int j;
	int first_word = 1;

	while (s[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		while (i >= 0 && is_space(s[i]))
			i--;
		j = i;
		while (j >= 0 && !is_space(s[j]))
			j--;
		if (!first_word)
			write(1, " ", 1);
		write(1, &s[j + 1], i - j);
		first_word = 0;
		i = j;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
