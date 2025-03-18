#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>
#include <cmocka.h>

// Function to test (real code)
void* my_function_that_uses_malloc() {
    void* ptr = malloc(10);  // This will call __wrap_malloc in tests
    if (ptr == NULL) {
        return NULL;  // Handle malloc failure properly
    }
    return ptr;
}

// Test case
void test_malloc_failure(void** state) {
    (void) state;

    will_return(__wrap_malloc, NULL);

    // Call the function under test
    void* result = my_function_that_uses_malloc();

    // Assert malloc failure is handled (should return NULL)
    assert_null(result);
}
