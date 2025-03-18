#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

// Include the necessary test files here
#include "test_ft_isdigit.c"
#include "test_ft_isalpha.c"
#include "test_ft_strrchr.c"
#include "test_ft_memchr.c"
#include "test_ft_memcmp.c"
#include "test_ft_strnstr.c"
#include "test_ft_atoi.c"
#include "test_ft_calloc.c"
#include "test_ft_strdup.c"
#include "test_ft_substr.c"
#include "test_ft_strtrim.c"
#include "test_ft_split.c"
// #include "test_malloc_failure.c"
#include "test_ft_itoa.c"
#include "test_ft_bzero.c"
#include "test_ft_striteri.c"
#include "test_ft_lstnew_bonus.c"
#include "test_ft_lstadd_front_bonus.c"
#include "test_ft_lstsize_bonus.c"
#include "test_ft_lstlast_bonus.c"
#include "test_ft_lstadd_back_bonus.c"
#include "test_ft_lstdelone_bonus.c"

// Wrapper function to simulate malloc failure
void *__wrap_malloc(size_t size)
{
    (void)size; // Ignore the size
    return NULL; // Simulate malloc failure
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_ft_isdigit),
		cmocka_unit_test(test_ft_isalpha),
        cmocka_unit_test(test_ft_strrchr),
        cmocka_unit_test(test_ft_memchr),
        cmocka_unit_test(test_ft_memcmp),
        cmocka_unit_test(test_ft_strnstr),
        cmocka_unit_test(test_ft_atoi),
        cmocka_unit_test(test_ft_calloc),
        cmocka_unit_test(test_ft_strdup_normal),
        cmocka_unit_test(test_ft_strdup_empty),
        cmocka_unit_test(test_ft_strdup_large),
        cmocka_unit_test(test_ft_substr),
        cmocka_unit_test(test_ft_strtrim),
        cmocka_unit_test(test_ft_split),
        // cmocka_unit_test(test_malloc_failure),
        cmocka_unit_test(test_ft_itoa),
        cmocka_unit_test(test_ft_bzero),
        cmocka_unit_test(test_ft_striteri),
        cmocka_unit_test(test_ft_lstnew),
        cmocka_unit_test(test_ft_lstadd_front),
        cmocka_unit_test(test_ft_lstsize),
        cmocka_unit_test(test_ft_lstlast),
        cmocka_unit_test(test_ft_lstadd_back),
        cmocka_unit_test(test_ft_lstdelone),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

// gcc -o test_binary testsuite.c \
//     -I/$HOME/homebrew/Cellar/cmocka/1.1.7/include \
//     -L/$HOME/homebrew/Cellar/cmocka/1.1.7/lib \
//     -lcmocka
