#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_strncmp.c"  // Include the function we want to test

// Test case for ft_strncmp
void test_ft_strncmp(void **state)
{
	(void)state; // unused variable

    // Test: Equal strings
    assert_int_equal(ft_strncmp("hello", "hello", 5), 0);
    assert_int_equal(ft_strncmp("test", "test", 10), 0);

    // Test: Different strings
    assert_true(ft_strncmp("abc", "abd", 3) < 0);
    assert_true(ft_strncmp("abd", "abc", 3) > 0);

    // Test: One string is a prefix of another
    assert_true(ft_strncmp("abc", "abcd", 4) < 0);
    assert_true(ft_strncmp("abcd", "abc", 4) > 0);

    // Test: Limited comparison (should only compare up to 'n')
    assert_int_equal(ft_strncmp("abcdef", "abcxyz", 3), 0);
    assert_true(ft_strncmp("abcdef", "abcxyz", 4) < 0);

    // Test: Empty string comparisons
    assert_true(ft_strncmp("", "a", 1) < 0);
    assert_int_equal(ft_strncmp("", "", 5), 0);

    // Test: Null terminator within comparison range
    assert_true(ft_strncmp("abc", "abc\0def", 6) == 0);
}
