#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

int	ft_display_file(const char *file_path)
{
	const int	buffer_size = 1024;
	int			fd;
	int			bytes_read;
	char		buffer[buffer_size];

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)))
		write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_read == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error("File name missing.\n");
	else if (argc > 2)
		ft_error("Too many arguments.\n");
	else if (!ft_display_file(argv[1]))
		ft_error("Cannot read file.\n");
	return (0);
}
