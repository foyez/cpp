#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header file

static void test_ft_lstnew_valid_content()
{
    int value = 42;
    t_list *node = ft_lstnew(&value);

    assert_non_null(node);
    assert_non_null(node->content);
    assert_int_equal(*(int *)node->content, 42);
    assert_null(node->next);

    free(node);  // Clean up
}

static void test_ft_lstnew_null_content()
{
    t_list *node = ft_lstnew(NULL);

    assert_non_null(node);
    assert_null(node->content);
    assert_null(node->next);

    free(node);  // Clean up
}

void test_ft_lstnew(void **state)
{
	(void)state;

	test_ft_lstnew_valid_content();
	test_ft_lstnew_null_content();
}
