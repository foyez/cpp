#include "get_next_line.h"

char *ft_realloc(char *str, int old_size, int new_size)
{
	char *new_str;
	int i;

	if (!str)
		return (malloc(new_size));
	if (new_size <= 0)
		return (NULL);
	new_str = malloc(new_size);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < old_size)
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
