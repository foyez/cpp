int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char *ft_strrev(char *s)
{
	int i = 0;
	int size = ft_strlen(s);
	char tmp;

	while (i < size / 2)
	{
		tmp = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = tmp;
		i++;
	}
	return (s);
}

#include <stdio.h>

int main()
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}
