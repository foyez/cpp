#include <unistd.h>

int		ft_strlen(char *str);

void	ft_error(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
