#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	int		temp;

	if (!lst)
		return (NULL);
	cur = lst;
	while (cur->next)
	{
		if (cmp(cur->data, cur->next->data) == 0)
		{
			// swap the data
			temp = cur->data;
			cur->data = cur->next->data;
			cur->next->data = temp;
			// restart from the beginning
			cur = lst;
		}
		else
		{
			// move to the next node
			cur = cur->next;
		}
	}
	return (lst);
}

#include <stdio.h>

t_list	*create_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = create_node(4);
	lst->next = create_node(2);
	lst->next->next = create_node(5);
	lst->next->next->next = create_node(1);
	printf("Original list: ");
	print_list(lst);
	lst = sort_list(lst, ascending);
	printf("Sorted list: ");
	print_list(lst);
	// Free memory
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
