#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int len = ft_strlen(src);
	char *dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strdup("hello"));
	return (0);
}
