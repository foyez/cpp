#include <stdlib.h>

size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j;
	int found;

	while (s[i])
	{
		found = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				found = 1;
			j++;
		}
		if (!found)
			break;
		i++;
	}
	return (i);
}

size_t ft_strcspn(const char *s, const char *reject)
{
	int i = -1;
	int j;

	while (s[++i])
	{
		j = -1;
		while (reject[++j])
			if (s[i] == reject[j])
				return i;
	}
	return i;
}

#include <stdio.h>

int main(void)
{
	const char *s = "abc123";
	printf("ft_strspn: %zu\n", ft_strspn(s, "abc"));    // → 3
	printf("ft_strcspn: %zu\n", ft_strcspn(s, "123"));  // → 3
	return 0;
}
