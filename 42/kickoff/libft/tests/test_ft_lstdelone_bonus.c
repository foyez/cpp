#include "libfttest.h"

#include <stdio.h>

static void mock_del(void *content)
{
	check_expected(content);
	free(content);
}

void test_ft_lstdelone(void **state)
{
	(void)state;

	t_list *node = malloc(sizeof(t_list));
	assert_non_null(node);

	char *content = malloc(10);
	assert_non_null(content);
	snprintf(content, 10, "TestData");
	node->content = content;
	node->next = NULL;

	expect_value(mock_del, content, content);

	ft_lstdelone(node, mock_del);
}
