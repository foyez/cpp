#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_atoi.c"  // Include the function we want to test

// Test case for ft_atoi
void test_ft_atoi(void **state)
{
    (void)state; // unused variable

    // Test: Normal case with positive number
    assert_int_equal(ft_atoi("42"), 42);

    // Test: Normal case with negative number
    assert_int_equal(ft_atoi("-42"), -42);

    // Test: Normal case with number having leading spaces
    assert_int_equal(ft_atoi("   123"), 123);

    // Test: Case with number and extra characters after
    assert_int_equal(ft_atoi("123abc"), 123);  // Only the number part is considered

    // Test: Case with leading zeros
    assert_int_equal(ft_atoi("000045"), 45);  // Leading zeros are ignored

    // Test: Case with positive number and a plus sign
    assert_int_equal(ft_atoi("+42"), 42);

    // Test: Case with empty string
    assert_int_equal(ft_atoi(""), 0);  // Empty string should return 0

    // Test: Case with only spaces
    assert_int_equal(ft_atoi("   "), 0);  // Only spaces should return 0

    // Test: Case with negative number and spaces
    assert_int_equal(ft_atoi("   -567"), -567);  // Should handle spaces and negative sign correctly

    // Test: Invalid string with no number
    assert_int_equal(ft_atoi("abc"), 0);  // Non-numeric string should return 0
}
