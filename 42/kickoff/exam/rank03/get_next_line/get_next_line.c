#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int bytes_read = 0;
	static char buf[BUFFER_SIZE];
	static int buf_idx = 0;
	char *line;
	int line_idx = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = malloc(10000);
	if (!line)
		return (NULL);

	while (1)
	{
		if (buf_idx >= bytes_read)
		{
			buf_idx = 0;
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read <= 0)
				break;
		}
		line[line_idx++] = buf[buf_idx++];
		if (line[line_idx - 1] == '\n')
			break;
	}
	if (line_idx > 0)
	{
		line[line_idx] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
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
