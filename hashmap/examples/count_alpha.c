#include <stdio.h>

void	count_alpha(char *s)
{
	int freq[26] = {0};
	int i;

	i = -1;
	while (s[++i])
	{
		char c = s[i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c >= 'a' && c <= 'z')
			freq[c - 'a']++;
	}
	i = -1;
	while (++i < 26)
	{
		if (freq[i])
		{
			printf("%d%c", freq[i], i + 'a');
			if (freq[i + 1])
				printf(", ");
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
	return (0);
}
