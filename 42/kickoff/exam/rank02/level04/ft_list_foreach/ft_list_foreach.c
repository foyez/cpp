#include "ft_list.h"
#include <stdlib.h>

void ft_list_foreach(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		if (lst->data != NULL)
			f(lst->data);
		lst = lst->next;
	}
}

t_list	*create_node(void *data)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

#include <stdio.h>

void print_str(void *data)
{
	char *p = (char *)data;
	printf("%s\n", p);
}

int main()
{
	t_list *n1 = create_node("hi");
	t_list *n2 = create_node("how");
	t_list *n3 = create_node("are");

	n1->next = n2;
	n2->next = n3;

	ft_list_foreach(n1, print_str);

	return 0;
}
