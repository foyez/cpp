#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	unsigned char map[256] = {0}; // Lookup table for ASCII characters
	int i;
	unsigned char c;

	i = -1;
	while (s1[++i])
	{
		c = (unsigned char)s1[i];
		if (!map[c])
		{
			map[c] = 1;
			ft_putchar(c);
		}
	}

	i = -1;
	while (s2[++i])
	{
		c = (unsigned char)s2[i];
		if (!map[c])
		{
			map[c] = 1;
			ft_putchar(c);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	return (0);
}
