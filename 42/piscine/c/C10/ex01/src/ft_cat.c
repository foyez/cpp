#include "../includes/ft.h"

void	ft_error(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}
void	print_error(const char *filepath)
{
	ft_error(basename((char *)filepath));
	ft_error(": ");
	ft_error(strerror(errno));
	ft_error("\n");
}

int	ft_cat(const char *filepath)
{
	const int	buffer_size = 30720;
	int			fd;
	ssize_t		bytes_read;
	char		buffer[buffer_size];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)))
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) < 0)
		{
			close(fd);
			return (0);
		}
	}
	if (bytes_read < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	ft_read_stdin(void)
{
	char	buf;

	while (read(0, &buf, 1))
		write(STDOUT_FILENO, &buf, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		if (errno == 0)
			ft_read_stdin();
		else
			print_error(argv[0]);
	}
	else
	{
		i = 0;
		while (++i < argc)
			if (!ft_cat(argv[i]))
				print_error(argv[i]);
	}
	return (0);
}
