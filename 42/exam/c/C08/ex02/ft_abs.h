/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:09:15 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/04 05:53:14 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value)			   \
	({                         \
		typeof(Value) result;  \
		if ((Value) >= 0)      \
		{                      \
			result = (Value);  \
		}                      \
		else                   \
		{                      \
			result = -(Value); \
		}                      \
		result;                \
	})

#endif
