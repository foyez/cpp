void	ft_puterr(void);
int		validate_number(int argc, char **argv);
int		ft_atoi(const char *str);

int	is_valid_arguments(int argc)
{
	if (!(argc == 2 || argc == 3))
		return (ft_puterr(), 0);
	return (1);
}

int	validate_number(int argc, char **argv)
{
	int		res;
	char	*nbr;

	if (argc == 2)
		nbr = argv[1];
	else if (argc == 3)
		nbr = argv[2];
	else
		nbr = "-1";
	res = ft_atoi(nbr);
	if (res < 0)
		return (ft_puterr(), -1);
	return (res);
}
