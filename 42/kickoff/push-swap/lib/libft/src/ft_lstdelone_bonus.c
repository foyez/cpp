/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:56 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/17 13:05:51 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// void del(void *content)
// {
// 	free(content);
// 	printf("Node content freed!");
// }

// int main(void)
// {
// 	t_list *node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (1);

// 	node->content = malloc(20);
// 	if (!node->content)
// 	{
// 		free(node);
// 		return (1);
// 	}
// 	node->next = NULL;
// 	ft_lstdelone(node, del);

// 	return (0);
// }
