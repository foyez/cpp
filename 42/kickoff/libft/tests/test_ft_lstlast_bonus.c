#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header file

static void test_ft_lstlast(void **state)
{
    (void)state;

    // Test: empty list
	t_list *empty_list = NULL;
	assert_null(ft_lstlast(empty_list));

    // Test: list with one element
    t_list *head = ft_lstnew("One");
    assert_non_null(head);
    assert_ptr_equal(ft_lstlast(head), head);

	// Test: list with multiple elements
	t_list *node2 = ft_lstnew("One");
	t_list *node3 = ft_lstnew("Two");
	head->next = node2;
    node2->next = node3;

	assert_non_null(node2);
	assert_non_null(node3);
	assert_ptr_equal(ft_lstlast(head), node3);

	free(node3);
    free(node2);
	free(head);
}
