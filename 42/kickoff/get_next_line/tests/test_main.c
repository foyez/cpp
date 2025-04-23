#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("tests/test1.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);  // Expecting lines from the file
        free(line);  // Free after use
    }
	line = get_next_line(fd);
	printf("%s", line);
    free(line);

    close(fd);
    return (0);
}
