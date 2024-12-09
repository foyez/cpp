#include <stdlib.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_common_substring(char *substr, char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!ft_strstr(strs[i], substr))
			return (0);
		i++;
	}
	return (1);
}

void	str_maxlenoc(int len, char **strs)
{
	char	*first_str;
	int		first_len;
	char	*result;
	char	*tmp;
	int		maxlen;
	int		substrlen;
	int		start;

	first_str = strs[0];
	first_len = ft_strlen(first_str);
	result = NULL;
	maxlen = 0;
	substrlen = 0;
	while (++substrlen <= first_len)
	{
		start = -1;
		while (++start <= first_len - substrlen)
		{
			tmp = (char *)malloc(sizeof(char) * (substrlen + 1));
			ft_strncpy(tmp, &first_str[start], substrlen);
			tmp[substrlen] = '\0';
			// skiping first string
			if (!is_common_substring(tmp, strs + 1, len - 1))
			{
				free(tmp);
				continue ;
			}
			if (substrlen > maxlen)
			{
				maxlen = substrlen;
				if (result)
					free(result);
				result = (char *)malloc((substrlen + 1) * sizeof(char));
				if (!result)
					return ;
				ft_strcpy(result, tmp);
				free(tmp);
			}
		}
	}
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
}

int	main(int argc, char **argv)
{
	// char	*strs[] = {"abcd", "bc"};
	// str_maxlenoc(2, strs);
	if (argc >= 2)
		str_maxlenoc(argc - 1, argv + 1);
	write(1, "\n", 1);
	return (0);
}
