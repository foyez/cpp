#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void ft_wdmatch(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len = 0;

	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				len++;
				break;
			}
			j++;
		}
		i++;
	}
	if (len == i)
		ft_putstr(s1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_wdmatch(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
