#include <stdlib.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return (char *)(s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s\n", ft_strpbrk("what", "at"));
	printf("%s\n", strpbrk("what", "at"));
	return (0);
}
