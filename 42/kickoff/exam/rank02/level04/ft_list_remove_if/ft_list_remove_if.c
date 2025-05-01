#include "ft_list.h"
#include <stdlib.h>


void	ft_list_remove_if(t_list **lst, void *data, int (*cmp)())
{
	t_list *tmp;

	if (lst == NULL || *lst == NULL)
		return;
	if (cmp((*lst)->data, data) == 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->data);
		free(tmp);
		ft_list_remove_if(lst, data, cmp);
	}
	else
	{
		ft_list_remove_if(&(*lst)->next, data, cmp);
	}
}

#include <stdio.h>

int cmp_int(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d\n", *(int *)lst->data);
        lst = lst->next;
    }
}

t_list *create_node(int value)
{
    int *data = malloc(sizeof(int));
    *data = value;
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = NULL;
    return node;
}

int main(void)
{
    // Build list: 10 -> 42 -> 30 -> 42 -> 50
    t_list *a = create_node(10);
    t_list *b = create_node(42);
    t_list *c = create_node(30);
    t_list *d = create_node(42);
    t_list *e = create_node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    printf("Before:\n");
    print_list(a);

    int target = 42;
    ft_list_remove_if(&a, &target, cmp_int);

    printf("\nAfter:\n");
    print_list(a);

    // Cleanup
    while (a)
    {
        t_list *tmp = a;
        a = a->next;
        free(tmp->data);
        free(tmp);
    }

    return 0;
}
