#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char  *get_next_line(int fd);
char *ft_realloc(char *str, int old_size, int new_size);

#endif
