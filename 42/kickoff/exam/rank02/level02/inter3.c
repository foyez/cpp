#include <unistd.h>

typedef struct {
	char *key;
	int value;
}	map;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_intersection(char *s1, char *s2)
{
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_intersection(argv[1], argv[2]);
	return (0);
}
