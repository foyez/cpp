#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_present(char *s, char c, int pos)
{
	int i = -1;

	while (++i < pos)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

void ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		if (!is_present(s1, s1[i], i))
			ft_putchar(s1[i]);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		if (!is_present(s1, s2[j], i) && !is_present(s2, s2[j], j))
			ft_putchar(s2[j]);
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	return (0);
}
