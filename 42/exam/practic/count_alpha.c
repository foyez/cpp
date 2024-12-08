#include <stdio.h>

void	count_alpha(char *str)
{
	int				occ[26];
	unsigned char	alpha[27];
	int				i;
	int				j;

	i = -1;
	while (++i < 26)
		occ[i] = 0;
	i = -1;
	while (++i < 27)
		alpha[i] = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32; // lower
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!occ[str[i] - 'a'])
				alpha[j++] = str[i];
			occ[str[i] - 'a']++;
		}
	}
	i = -1;
	while (alpha[++i])
	{
		printf("%d%c", occ[alpha[i] - 'a'], alpha[i]);
		if (alpha[i + 1])
			printf(", ");
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
	return (0);
}
