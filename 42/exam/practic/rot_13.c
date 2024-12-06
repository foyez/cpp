#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a'
				&& str[i] <= 'm'))
			str[i] += 13;
		else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n'
				&& str[i] <= 'z'))
			str[i] -= 13;
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	ft_putchar('\n');
	return (0);
}

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>
