void	ft_puterr(void);
int		validate_number(int argc, char **argv);

int	is_valid_arguments(int argc)
{
	int	nbr;

	if (!(argc == 2 || argc == 3))
		return (ft_puterr(), 0);
	return (1);
}

int	validate_number(int argc, char **argv)
{
	int		i;
	int		res;
	char	*nbr;

	if (argc == 2)
		nbr = argv[1];
	else if (argc == 3)
		nbr = argv[2];
	else
		nbr = "-1";
	i = 0;
	res = 0;
	while (nbr[i] != '\0')
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (ft_puterr(), -1);
		res = res * 10 + nbr[i] - '0';
		i++;
	}
	return (res);
}
