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
	while (++i < old_size && str[i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char *get_next_line(int fd)
{
	static int bytes_read = 0;
	static char buf[BUFFER_SIZE];
	static int buf_idx = 0;
	int capacity = 64;
	char *line;
	int len = 0;

	line = malloc(capacity);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (free(line), NULL);

	while (1)
	{
		if (buf_idx >= bytes_read)
		{
			buf_idx = 0;
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read <= 0)
				break;
		}
		if (len + 1 >= capacity)
		{
			char *new_line = ft_realloc(line, capacity, capacity * 2);
			if (!new_line)
				return (free(line), NULL);
			line = new_line;
			capacity *= 2;
		}
		line[len++] = buf[buf_idx++];
		if (line[len - 1] == '\n')
			break;
	}
	if (len == 0)
		return (free(line), NULL);
	line[len] = '\0';
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
