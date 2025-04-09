/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabic <zbabic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:28:11 by zbabic            #+#    #+#             */
/*   Updated: 2025/03/21 16:11:27 by zbabic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

int		ft_put_pointer_fd(void *ptr, int fd);
int		handle_p(va_list args, size_t *num_char);

size_t	f_calc_num_char_for_int(int number);
int		handle_di(va_list args, size_t *num_char);

size_t	f_calc_num_char_for_uint(unsigned int num, size_t base);
int		ft_put_uint_base(unsigned int nbr, char *base);
int		handle_hex(va_list args, size_t *num_char, int uppercase);
int		handle_u(va_list args, size_t *num_char);

int		handle_c(va_list args, size_t *num_char);
int		handle_s(va_list args, size_t *num_char);
int		ft_printf(const char *format, ...);

#endif