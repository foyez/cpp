#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header

// Test cases for ft_itoa
void test_ft_itoa(void **state)
{
    (void)state;  // Unused parameter

    // Test: Zero
    char *result = ft_itoa(0);
    assert_string_equal(result, "0");
    free(result);

    // Test: Positive numbers
    result = ft_itoa(42);
    assert_string_equal(result, "42");
    free(result);

    result = ft_itoa(123456);
    assert_string_equal(result, "123456");
    free(result);

    // Test: Negative numbers
    result = ft_itoa(-42);
    assert_string_equal(result, "-42");
    free(result);

    result = ft_itoa(-123456);
    assert_string_equal(result, "-123456");
    free(result);

    // Test: INT_MAX (2147483647)
    result = ft_itoa(2147483647);
    assert_string_equal(result, "2147483647");
    free(result);

    // Test: INT_MIN (-2147483648)
    result = ft_itoa(-2147483648);
    assert_string_equal(result, "-2147483648");
    free(result);

    // Test: Smallest negative number (-1)
    result = ft_itoa(-1);
    assert_string_equal(result, "-1");
    free(result);
}
