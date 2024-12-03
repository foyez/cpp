int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0); // Numbers <= 1 are not prime
	if (nb <= 3)
		return (1); // 2 and 3 are prime numbers
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0); // Eliminate multiples of 2 and 3
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0); // Eliminate factors
		i += 6;         // Check numbers of the form 6k ± 1
	}
	return (1); // Prime if no factors are found
}
