#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header file

static void test_ft_lstsize(void **state)
{
    (void)state;

    // Test: empty list
	t_list *empty_list = NULL;
	assert_int_equal(ft_lstsize(empty_list), 0);

	// Test: list with multiple elements
	t_list *head = ft_lstnew("One");
	t_list *node1 = ft_lstnew("Two");
	head->next = node1;

	assert_non_null(head);
	assert_non_null(node1);
	assert_int_equal(ft_lstsize(head), 2);

	free(node1);
	free(head);
}
