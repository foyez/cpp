#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdlib.h>

#include "../libft.h"  // Include the function prototype

void test_ft_strjoin(void **state) {
    (void)state;  // Unused variable

    // Test: Normal case
    char *result = ft_strjoin("Hello, ", "World!");
    assert_string_equal(result, "Hello, World!");
    free(result);

    // Test: First string is empty
    result = ft_strjoin("", "World!");
    assert_string_equal(result, "World!");
    free(result);

    // Test: Second string is empty
    result = ft_strjoin("Hello, ", "");
    assert_string_equal(result, "Hello, ");
    free(result);

    // Test: Both strings are empty
    result = ft_strjoin("", "");
    assert_non_null(result);
    assert_string_equal(result, "");
    free(result);

    // Test: First string is NULL
    result = ft_strjoin(NULL, "World!");
    assert_string_equal(result, "World!");
    free(result);

    // Test: Second string is NULL
    result = ft_strjoin("Hello, ", NULL);
    assert_string_equal(result, "Hello, ");
    free(result);

    // Test: Both strings are NULL
    result = ft_strjoin(NULL, NULL);
    assert_string_equal(result, "");
    free(result);
}
