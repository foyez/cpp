#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int size)
{
	write(1, str, size);
}

void	ft_wordmatch(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				len++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (len == i)
		ft_putstr(s1, len);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_wordmatch(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux"
// "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $
