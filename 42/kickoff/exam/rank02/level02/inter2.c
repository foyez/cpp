#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_intersection(char *s1, char *s2)
{
	unsigned char map[256] = {0};
	int i;

	i = -1;
	while (s1[++i])
		map[(unsigned char)s1[i]] = 1;

	i = -1;
	while (s2[++i])
	{
		unsigned char c = (unsigned char)s2[i];
		if (map[c])
		{
			ft_putchar(c);
			map[c] = 0;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_intersection(argv[1], argv[2]);
	return (0);
}
