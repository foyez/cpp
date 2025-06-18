/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:16:00 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/18 03:07:53 by kaahmed          ###   ########.fr       */
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
	int		precision_set;
	int		zero_pad;
	int		plus_sign;
	int		space;
	int		alt_form;
}			t_flags;

typedef struct s_vars
{
	int		count;
	int		ret;
	int		len;
	int		zeros;
	int		contentlen;
	int		fd;
}			t_vars;

typedef struct s_hex_args
{
	int		low;
	int		prefixlen;
}			t_hex_args;

int			ft_printf(const char *str, ...);
int			ft_fprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list args);
const char	*parse_flags(const char *format, t_flags *flags);
int			handle_format(int fd, char c, va_list *args, t_flags flags);
int			print_char(int fd, char c, t_flags flags);
int			print_str(int fd, const char *str, t_flags flags);
int			print_nbr(int fd, int n, t_flags flags);
int			print_unsigned(int fd, unsigned int n, t_flags flags);
int			print_ptr(int fd, unsigned long ptr, t_flags flags);
int			print_hex(int fd, unsigned int num, t_flags flags, int low);
int			ft_putchar(int fd, char c);
int			ft_putnchar(int fd, char c, int n);
int			ft_putnstr(int fd, const char *s, int n);
int			ft_putpad(int fd, int width, int contentlen, int zero_pad);
int			ft_putbuf(int fd, char *buf, int len, int zeros);
int			safe_count(int ret, int *count);

#endif
