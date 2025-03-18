#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <ctype.h>

#include "../ft_isdigit.c"  // Include the function we want to test

// Test case for ft_isdigit
void test_ft_isdigit(void **state)
{
    (void)state; // unused variable

    // Test: Valid digits
    assert_int_equal(ft_isdigit('0'), isdigit('0'));  // '0' should return true
    assert_int_equal(ft_isdigit('5'), isdigit('5'));  // '5' should return true
    assert_int_equal(ft_isdigit('9'), isdigit('9'));  // '9' should return true

    // Test: Invalid digits (non-digit characters)
    assert_int_equal(ft_isdigit('a'), 0);  // 'a' should return false
    assert_int_equal(ft_isdigit('Z'), 0);  // 'Z' should return false
    assert_int_equal(ft_isdigit(' '), 0);  // Space should return false
    assert_int_equal(ft_isdigit('\n'), 0); // Newline should return false
}

// int main(void)
// {
//     const struct CMUnitTest tests[] = {
//         cmocka_unit_test(test_ft_isdigit),
//     };

//     return cmocka_run_group_tests(tests, NULL, NULL);
// }
