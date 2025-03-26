/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:23:23 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 14:49:18 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
/// @param lst
/// @return
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	if (!lst)
		return (NULL);
	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur);
}
