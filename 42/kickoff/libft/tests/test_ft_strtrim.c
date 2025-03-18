#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your function declarations

// // ✅ Mock malloc to simulate failure
// static void *__wrap_malloc(size_t size)
// {
//     if (mock_type(int))  // If test forces failure, return NULL
//         return NULL;
//     return malloc(size);
// }

// ✅ Combined Test Function
void test_ft_strtrim(void **state)
{
    (void)state;

    // Test: Basic trimming (spaces)
    char *trimmed = ft_strtrim("   Hello World!   ", " ");
    assert_string_equal(trimmed, "Hello World!");
    free(trimmed);

    // Test: Trimming multiple characters
    trimmed = ft_strtrim("---Hello World!!!---", "-!");
    assert_string_equal(trimmed, "Hello World");
    free(trimmed);

    // Test: No trimming needed
    trimmed = ft_strtrim("Hello", " ");
    assert_string_equal(trimmed, "Hello");
    free(trimmed);

    // Test: All characters removed
    trimmed = ft_strtrim("!!!!!", "!");
    assert_string_equal(trimmed, "");
    free(trimmed);

    // Test: Empty string input
    trimmed = ft_strtrim("", " ");
    assert_string_equal(trimmed, "");
    free(trimmed);

    // Test: `set` is NULL (returns duplicate of `s1`)
    trimmed = ft_strtrim("  Hello  ", NULL);
    assert_null(trimmed);

    // Test: `s1` is NULL (should return NULL)
    trimmed = ft_strtrim(NULL, " ");
    assert_null(trimmed);

    // // ✅ Simulating malloc failure
    // will_return(__wrap_malloc, 1);  // Force malloc to return NULL
    // trimmed = ft_strtrim("   Hello   ", " ");
    // assert_null(trimmed);  // Should return NULL due to failed malloc
}
