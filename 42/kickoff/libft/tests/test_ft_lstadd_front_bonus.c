#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../libft.h"  // Include your libft header file

static void test_ft_lstadd_front(void **state)
{
    (void)state;

    t_list *head = ft_lstnew("World");
    t_list *new_node = ft_lstnew("Hello");

    assert_non_null(head);
    assert_non_null(new_node);

    ft_lstadd_front(&head, new_node);

    assert_ptr_equal(head, new_node);
    assert_ptr_equal(head->next, head->next);
    assert_string_equal((char *)head->content, "Hello");
    assert_string_equal((char *)head->next->content, "World");

    free(head->next);
    free(head);
}
