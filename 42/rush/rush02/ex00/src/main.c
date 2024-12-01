#include <stdlib.h>

#define DEFAULT_DICT "dict/numbers.en.dict"

void	ft_error(char *str);
int		validate_args(int argc, char **argv, char *default_dict);

int	error(void)
{
	ft_error("Error\n");
	return (EXIT_FAILURE);
}

int	dict_error(void)
{
	ft_error("Dict Error\n");
	return (EXIT_FAILURE);
}

void	print_num_words(char *file_path, char *nbr)
{
	(void)file_path;
	(void)nbr;
}

int	main(int argc, char **argv)
{
	int	err_code;

	err_code = validate_args(argc, argv, DEFAULT_DICT);
	if (err_code == 0)
		return (error());
	if (err_code == -1)
		return (dict_error());
	if (argc == 2)
		init(DEFAULT_DICT, argv[1]);
	else if (argc == 3)
		init(argv[1], argv[2]);
	return (EXIT_SUCCESS);
}
