#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdlib.h>
#include <string.h>

#include "../libft.h"  // Include your function prototype

void test_ft_substr(void **state) {
    (void)state;  // Unused variable

    // Test: Normal substring extraction
    char *result = ft_substr("Hello, World!", 7, 5);
    assert_string_equal(result, "World");
    free(result);

    // Test: Extract from the beginning
    result = ft_substr("Hello", 0, 4);
    assert_string_equal(result, "Hell");
    free(result);

    // Test: Start is beyond the string length
    result = ft_substr("Hello", 10, 3);
    assert_non_null(result);
    assert_string_equal(result, "");  // Should return an empty string
    free(result);

    // Test: Length exceeds available characters
    result = ft_substr("Hello", 3, 10);
    assert_string_equal(result, "lo");
    free(result);

    // Test: Length is zero
    result = ft_substr("Hello", 2, 0);
    assert_non_null(result);
    assert_string_equal(result, "");  // Should return an empty string
    free(result);

    // Test: Passing a NULL string
    result = ft_substr(NULL, 2, 3);
    assert_null(result);  // Should return NULL

    // Test: The entire string
    result = ft_substr("Hello", 0, 5);
    assert_string_equal(result, "Hello");
    free(result);

    // Test: Extract last character
    result = ft_substr("Hello", 4, 1);
    assert_string_equal(result, "o");
    free(result);
}
