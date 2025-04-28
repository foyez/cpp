unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	int				bit;
	unsigned char	res;

	i = -1;
	while (++i < 8)
	{
		bit = ((octet >> i) & 1) + '0';
	}
}
