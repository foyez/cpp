/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:16:00 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 20:43:30 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				left_align;
	int				width;
	int				precision;
	int				precision_set;
	int				zero_pad;
	int				plus_sign;
	int				space;
	int				alt_form;
}					t_flags;

typedef struct s_vars
{
	int		count;
	int		ret;
	int		len;
	int		zeros;
	int		contentlen;
}	t_vars;

int			ft_printf(const char *str, ...);
const char	*parse_flags(const char *format, t_flags *flags);
int			handle_format(char c, va_list *args, t_flags flags);
int			print_char(char c, t_flags flags);
int			print_str(const char *str, t_flags flags);
int			print_nbr(int n, t_flags flags);
int			print_unsigned(unsigned int n, t_flags flags);
int			print_ptr(unsigned long ptr, t_flags flags);
int			print_hex(unsigned int num, t_flags flags, int low);
int			ft_putchar(char c);
int			ft_putnchar(char c, int n);
int			ft_putnstr(const char *s, int n);
int			ft_putpad(int width, int contentlen, int zero_pad);
int			ft_putbuf(char *buf, int len, int zeros);
int			safe_count(int ret, int *count);

#endif
