#include "utils.h"
#include <stdlib.h>

void	print_number_words(int number);

int	main(int argc, char **argv)
{
	int	nbr;

	if (!is_valid_arguments(argc))
		return (EXIT_FAILURE);
	nbr = validate_number(argc, argv);
	if (nbr == -1)
		return (EXIT_FAILURE);
	print_number_words(nbr);
	return (EXIT_SUCCESS);
}
