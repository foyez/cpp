#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_strrchr.c"  // Include the function we want to test

// Test case for ft_strrchr
void test_ft_strrchr(void **state)
{
    (void)state; // unused variable

    // Test: Character found in the string
    assert_string_equal(ft_strrchr("hello world", 'o'), "orld");
    assert_string_equal(ft_strrchr("hello world", 'l'), "ld");

    // Test: Character not found
    assert_null(ft_strrchr("hello world", 'x'));

    // Test: Character is null terminator
    assert_string_equal(ft_strrchr("hello world", '\0'), "");

    // Test: Single character string
    assert_string_equal(ft_strrchr("a", 'a'), "a");
    assert_null(ft_strrchr("a", 'b'));

    // Test: Empty string
    assert_null(ft_strrchr("", 'a'));
}
