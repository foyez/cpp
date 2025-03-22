#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
void ft_putchar(char c);
int ft_print_str(char *str, int left_align, int width, int precision);

#endif
