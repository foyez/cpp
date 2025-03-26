/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:16:55 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/17 16:39:49 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("world");
// 	t_list *node2 = ft_lstnew("hello");

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);

// 	t_list *cur = head;
// 	while (cur)
// 	{
// 		printf("%s ", (char *)cur->content);
// 		cur = cur->next;
// 	}

// 	return (0);
// }
