#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../ft_calloc.c"  // Include the function we want to test

// // ✅ Mock malloc to simulate failure
// static void *__wrap_malloc(size_t size)
// {
//     if (mock_type(int))  // If test forces failure, return NULL
//         return NULL;
//     return malloc(size);
// }

// Test case for ft_calloc
void test_ft_calloc(void **state)
{
    (void)state; // unused variable

    // Test: Normal case with small memory allocation (5 elements of type int)
    int *arr = (int *)ft_calloc(5, sizeof(int));
    assert_non_null(arr);  // Ensure that the pointer is not NULL

    // Verify that the memory is initialized to 0
    for (int i = 0; i < 5; i++) {
        assert_int_equal(arr[i], 0);  // All elements should be 0
    }

    // Test: Normal case with a large allocation (100 elements of type char)
    char *char_arr = (char *)ft_calloc(100, sizeof(char));
    assert_non_null(char_arr);  // Ensure that the pointer is not NULL

    // Verify that the memory is initialized to 0
    for (int i = 0; i < 100; i++) {
        assert_int_equal(char_arr[i], 0);  // All elements should be 0
    }

    // Test: Edge case with 0 elements (should return a unique pointer)
    void *zero_arr = ft_calloc(0, sizeof(int));
    assert_non_null(zero_arr);  // Should not return NULL

    // // Test: Allocation failure due to insufficient memory (simulated with mock)
    // will_return(__wrap_malloc, 1);  // Force malloc to return NULL
    // int *malloc_arr = ft_calloc(0, sizeof(int));
    // assert_null(malloc_arr);  // Should return NULL due to failed malloc

    // Free allocated memory after testing
    free(arr);
    free(char_arr);
	free(zero_arr);
    // free(malloc_arr);
}
