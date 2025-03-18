#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_strnstr.c"

// Test case for ft_strnstr
void test_ft_strnstr(void **state)
{
    (void)state; // unused variable
    const char *big = "abcdef";
    const char *small = "def";
    const char *empty = "";
    const char *nonexistent = "xyz";

    // Test: Small string is found in big string within the specified length
    assert_string_equal(ft_strnstr(big, small, 6), big + 3);  // "def" starts at index 3

    // Test: Small string is found in big string, but len is less than the full length
    assert_null(ft_strnstr(big, small, 3));  // Only "abc" is checked, so "def" isn't found

    // Test: Small string is empty, should return the whole "big" string
    assert_string_equal(ft_strnstr(big, empty, 6), big);

    // Test: Small string doesn't exist in big string
    assert_null(ft_strnstr(big, nonexistent, 6));

    // Test: Small string is longer than big string, should return NULL
    assert_null(ft_strnstr(big, "abcdefg", 6));  // "abcdefg" can't fit in "abcdef"

    // Test: Boundary condition with an empty big string and small string not empty
    assert_null(ft_strnstr("", "a", 0));  // Empty big string and non-empty small string

    // Test: Boundary condition with big string as empty and small string empty
    assert_string_equal(ft_strnstr("", "", 0), "");  // Empty big string and small string should return empty
}
