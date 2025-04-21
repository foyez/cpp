/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:16:00 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/21 17:01:23 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		left_align;
	int		width;
	int		precision;
	int		zero_pad;
	int		plus_sign;
	int		space;
	int		alt_form;
}			t_flags;

// int			ft_printf(const char *str, ...);
// int			ft_handle_format(char c, va_list *args, t_flags flags);
// int			ft_print_char(char c, t_flags flags);
// int			ft_print_str(const char *str, t_flags flags);
// int			ft_print_nbr(int n, t_flags flags);
// int			ft_print_unsigned(unsigned int n, t_flags flags);
// int			ft_print_ptr(unsigned long long ptr, t_flags flags);
// int			ft_print_hex(unsigned int num, t_flags flags, int low);
// const char	*ft_parse_flags(const char *format, t_flags *flags);
// int			ft_putchar(char c);
// int			ft_putstr(char *str);
// int			ft_pad_width(int width, int size, int zero);
// int			ft_longlen(long nb);
// int			ft_error(va_list args);

#endif
