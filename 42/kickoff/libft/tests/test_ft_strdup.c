#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_strdup.c"  // Include the function we want to test

// Test normal string duplication
void test_ft_strdup_normal(void **state)
{
    (void)state; // Unused variable

    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    // Ensure the duplicate is not NULL
    assert_non_null(duplicate);

    // Ensure the content is identical
    assert_string_equal(original, duplicate);

    // Ensure modifying duplicate does not affect original
    duplicate[0] = 'h';
    assert_int_not_equal(original[0], duplicate[0]);

    // Free allocated memory
    free(duplicate);
}

// Test empty string duplication
void test_ft_strdup_empty(void **state)
{
    (void)state; // Unused variable

    const char *original = "";
    char *duplicate = ft_strdup(original);

    // Ensure the duplicate is not NULL
    assert_non_null(duplicate);

    // Ensure the content is identical
    assert_string_equal(original, duplicate);

    free(duplicate);
}

// Test large string duplication
void test_ft_strdup_large(void **state)
{
    (void)state; // Unused variable

    const char *original = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *duplicate = ft_strdup(original);

    // Ensure the duplicate is not NULL
    assert_non_null(duplicate);

    // Ensure the content is identical
    assert_string_equal(original, duplicate);

    free(duplicate);
}
