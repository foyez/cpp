int is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_atoi(const char *s)
{
	int sign = 1;
	int res = 0;

	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi("-20"));
	return (0);
}
