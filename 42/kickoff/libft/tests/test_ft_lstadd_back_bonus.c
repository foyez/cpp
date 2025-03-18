#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header file

static void test_ft_lstadd_back(void **state)
{
    (void)state;

    t_list *head = ft_lstnew("Hello");
    t_list *new_node = ft_lstnew("World");

    assert_non_null(head);
    assert_non_null(new_node);

    ft_lstadd_back(&head, new_node);

    assert_ptr_equal(head, head);
    assert_ptr_equal(head->next, new_node);
	assert_string_equal((char *)head->content, "Hello");
	assert_string_equal((char *)head->next->content, "World");

    free(head->next);
    free(head);
}
