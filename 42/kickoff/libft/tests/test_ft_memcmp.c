#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_memcmp.c"

// Test case for ft_memcmp
void test_ft_memcmp(void **state)
{
    (void)state; // unused variable
    char data1[] = "abcdef";
    char data2[] = "abcdef";
    char data3[] = "abcdeg";
    char data4[] = "abcde";

    // Test: Identical memory blocks
    assert_int_equal(ft_memcmp(data1, data2, 6), 0);

    // Test: Different memory blocks (last character)
    assert_true(ft_memcmp(data1, data3, 6) < 0);

    // Test: Partial comparison (identical first 5 characters)
    assert_int_equal(ft_memcmp(data1, data3, 5), 0);

    // Test: Different length memory blocks
    assert_true(ft_memcmp(data1, data4, 6) > 0);

    // Test: Zero-length comparison
    assert_int_equal(ft_memcmp(data1, data3, 0), 0);
}
