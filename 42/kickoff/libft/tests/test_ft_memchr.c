#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>

#include "../ft_memchr.c"

// Test case for ft_memchr
void test_ft_memchr(void **state)
{
    (void)state; // unused variable
    char data[] = "Hello, world!";

    // Test: Finding a character in the middle
    assert_ptr_equal(ft_memchr(data, 'w', strlen(data)), &data[7]);

    // Test: Finding a character at the beginning
    assert_ptr_equal(ft_memchr(data, 'H', strlen(data)), &data[0]);

    // Test: Finding a character at the end
    assert_ptr_equal(ft_memchr(data, '!', strlen(data)), &data[12]);

    // Test: Character not found
    assert_null(ft_memchr(data, 'x', strlen(data)));

    // Test: Searching within a limited range (should not find 'w')
    assert_null(ft_memchr(data, 'w', 5));

    // Test: Null terminator should be found
    assert_ptr_equal(ft_memchr(data, '\0', strlen(data) + 1), &data[13]);

    // Test: Empty buffer
    assert_null(ft_memchr("", 'a', 0));
}
