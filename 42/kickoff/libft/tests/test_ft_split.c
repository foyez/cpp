#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"

// Test case for ft_split
void test_ft_split(void **state)
{
	(void)state; // unused variable

	// Test: normal splitting
	{
		char **result = ft_split("Hello World CMocka", ' ');

		assert_non_null(result);
		assert_string_equal(result[0], "Hello");
		assert_string_equal(result[1], "World");
		assert_string_equal(result[2], "CMocka");
		assert_null(result[3]);  // The array should end with NULL

		// Free the allocated memory
		for (int i = 0; result[i] != NULL; i++) {
			free(result[i]);
		}
		free(result);
	}

	// Test: splitting an empty string
	{
		char **result = ft_split("", ' ');

		assert_non_null(result);
		assert_null(result[0]); // Empty string should return an array with NULL

		// Free the allocated memory
		free(result);
	}

	// Test: string without delimiters
	{
		char **result = ft_split("Hello", ' ');

		assert_non_null(result);
		assert_string_equal(result[0], "Hello");
		assert_null(result[1]);  // Should end with NULL

		// Free the allocated memory
		free(result[0]);
		free(result);
	}

	// Test: string with only delimiters
	{
		char **result = ft_split("    ", ' ');

		assert_non_null(result);
		assert_null(result[0]);  // Should return an array with only NULL

		// Free the allocated memory
		free(result);
	}

	// // Test: NULL string input
	// {
	// 	char **result = ft_split(NULL, ' ');

	// 	assert_null(result);  // Should return NULL for a NULL input

	// 	// No need to free memory as result is NULL
	// }

	// // Test: malloc failure
	// {
	// 	 // Simulate malloc failure by returning NULL
	// 	 will_return(mock_malloc, NULL);

	// 	 char **result = ft_split("Hello World", ' ');

	// 	 assert_null(result);  // Should return NULL on malloc failure

	// 	 // No need to free memory as result is NULL
	// }

	// Test: splitting string with multiple spaces between words
	{
		char **result = ft_split("  Hello   World  ", ' ');

		assert_non_null(result);
		assert_string_equal(result[0], "Hello");
		assert_string_equal(result[1], "World");
		assert_null(result[2]);  // The array should end with NULL

		// Free the allocated memory
		for (int i = 0; result[i] != NULL; i++) {
			free(result[i]);
		}
		free(result);
	}
}

