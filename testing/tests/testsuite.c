#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>



#include "../src/mylib.h"

/* Mock malloc to simulate failure */
void *__wrap_malloc(size_t size) {
    check_expected(size);
    return mock_type(void *);
    // (void)size;
    // return NULL;
}

/* Test case for malloc failure */
static void test_allocate_array_failure(void **state) {
    (void)state;

    /* Expect malloc to be called with any size */
    expect_any(__wrap_malloc, size);

    /* Simulate malloc failure by returning NULL */
    will_return(__wrap_malloc, NULL);

    /* Call the function under test */
    int *arr = allocate_array(10);

    /* Assert that allocation failed */
    assert_null(arr);
}

// static void test_ft_calloc_valid_allocation(void **state) {
//     (void) state; // Unused

//     int *arr = (int *) ft_calloc(5, sizeof(int));
//     assert_non_null(arr);  // Ensure allocation was successful

//     // Check if memory is zero-initialized
//     for (int i = 0; i < 5; i++) {
//         assert_int_equal(arr[i], 0);
//     }

//     free(arr); // Free memory after test
// }

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_allocate_array_failure),
		// cmocka_unit_test(test_ft_calloc_valid_allocation),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
