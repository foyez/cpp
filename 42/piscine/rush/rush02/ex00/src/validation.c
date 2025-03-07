#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int	is_digits(char *str);
int	is_dict_file_exists(char *file_path);

int	validate_args(int argc, char **argv, char *default_dict)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!is_digits(argv[1]))
			return (0);
		if (!is_dict_file_exists(default_dict))
			return (-1);
	}
	if (argc == 3)
	{
		if (!is_dict_file_exists(argv[1]))
			return (-1);
		if (!is_digits(argv[2]))
			return (0);
	}
	return (1);
}
int	is_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_dict_file_exists(char *file_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
