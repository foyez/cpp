#include "list.h"
#include <stdlib.h>

void	ft_list_sort(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		f(cur->data);
		cur = cur->next;
	}
}

#include <stdio.h>

t_list	*create_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = malloc(sizeof(int));
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	*(int *)(node->data) = data;
	node->next = NULL;
	return (node);
}

void	print_int(void *data)
{
	printf("%d\n", *(int *)data);
}

int	main(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = create_node(4);
	lst->next = create_node(2);
	lst->next->next = create_node(5);
	lst->next->next->next = create_node(1);
	ft_list_sort(lst, print_int);
	// Free memory
	while (lst)
	{
		tmp = lst->next;
		free(lst->data);
		free(lst);
		lst = tmp;
	}
	return (0);
}
