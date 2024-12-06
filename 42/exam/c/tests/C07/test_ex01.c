#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int				*ft_range(int min, int max);

typedef struct
{
	const char	*name;
	int			min;
	int			max;
	int			*expected;
	int			expected_size;
	bool		should_be_null;
}				TestCase;

void	print_array(int *arr, int size)
{
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf("%d%s", arr[i], (i < size - 1) ? ", " : "");
	}
	printf("]");
}

bool	run_test(TestCase *test)
{
	int		*result;
	int		size;
	bool	is_passed;

	result = ft_range(test->min, test->max);
	size = test->max - test->min;
	is_passed = false;
	printf("%s: ", test->name);
	if (test->should_be_null)
	{
		is_passed = (result == NULL);
		printf(is_passed ? ANSI_COLOR_GREEN "PASS" : ANSI_COLOR_RED "FAIL");
		printf(ANSI_COLOR_RESET " (Expected: NULL, Got: %p)\n", (void *)result);
	}
	else
	{
		is_passed = (result != NULL && memcmp(test->expected, result, size
					* sizeof(int)) == 0);
		printf(is_passed ? ANSI_COLOR_GREEN "PASS" : ANSI_COLOR_RED "FAIL");
		printf(ANSI_COLOR_RESET "	(Expected: ");
		print_array(test->expected, test->expected_size);
		printf(", Got: ");
		result ? print_array(result, size) : printf("NULL");
		printf(")\n");
	}
	free(result);
	return (is_passed);
}

int	main(void)
{
	int	expected1[] = {0, 1, 2, 3, 4};
	int	expected2[] = {-3, -2, -1, 0, 1, 2};
	int	expected5[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
	int	total_tests;
	int	passed_tests;

	TestCase tests[] = {
		{"Positive range", 0, 5, expected1, 5, false},
		{"Negative to positive", -3, 3, expected2, 6, false},
		{"Invalid range (min > max)", 10, 5, NULL, 0, true},
		{"Invalid range (min == max)", 5, 5, NULL, 0, true},
		{"Negative range", -10, 0, expected5, 10, false},
	};
	total_tests = sizeof(tests) / sizeof(tests[0]);
	passed_tests = 0;
	for (int i = 0; i < total_tests; i++)
	{
		if (run_test(&tests[i]))
		{
			passed_tests++;
		}
	}
	printf("\nTest Summary: %d/%d tests passed.\n", passed_tests, total_tests);
	return (0);
}
