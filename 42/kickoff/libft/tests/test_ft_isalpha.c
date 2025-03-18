#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_isalpha.c"  // Include the function we want to test

// Test case for ft_isalpha
void test_ft_isalpha(void **state)
{
    (void)state; // unused variable

    // Test: Valid alphabets
    assert_int_equal(ft_isalpha('a'), 1);  // 'a' should return true
    assert_int_equal(ft_isalpha('z'), 1);  // 'z' should return true
    assert_int_equal(ft_isalpha('A'), 1);  // 'A' should return true
    assert_int_equal(ft_isalpha('Z'), 1);  // 'Z' should return true

    // Test: Invalid characters (non-alphabetic)
    assert_int_equal(ft_isalpha('0'), 0);  // '0' should return false
    assert_int_equal(ft_isalpha('9'), 0);  // '9' should return false
    assert_int_equal(ft_isalpha(' '), 0);  // Space should return false
    assert_int_equal(ft_isalpha('\n'), 0); // Newline should return false
}

