#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

char	*ft_strdup(char *src);

void	test_case(const char *test_name, char *expected)
{
	char	*result;

	result = ft_strdup(expected);
	printf("%s: ", test_name);
	if (strcmp(expected, result) == 0)
	{
		printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET);
	}
	printf(" (Expected: %s, Got: %s)\n", expected, result);
}

int	main(void)
{
	test_case("Test Case 1", "Hello");
	test_case("Test Case 2", "World");
	return (0);
}
