#include <stdlib.h>
#include <unistd.h>

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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
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

int	is_common_substr(char *substr, char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strstr(strs[i], substr))
			return (0);
		i++;
	}
	return (1);
}

void	ft_maxlenoc(char **strs, int size)
{
	char	*result;
	char	*tmp;
	int		substrlen;
	char	*firststr;
	int		firstlen;
	int		start;
	int		maxlen;

	result = NULL;
	maxlen = 0;
	firststr = strs[0];
	firstlen = ft_strlen(firststr);
	substrlen = 0;
	while (++substrlen <= firstlen)
	{
		start = -1;
		while (++start <= firstlen - substrlen)
		{
			tmp = (char *)malloc(sizeof(char) * (substrlen + 1));
			if (!tmp)
				return ;
			ft_strncpy(tmp, &firststr[start], substrlen);
			tmp[substrlen] = '\0';
			if (!is_common_substr(tmp, strs + 1, size - 1))
			{
				free(tmp);
				continue ;
			}
			if (substrlen > maxlen)
			{
				maxlen = substrlen;
				if (result)
					free(result);
				result = (char *)malloc(sizeof(char) * (substrlen + 1));
				if (!result)
					return ;
				ft_strncpy(result, tmp, substrlen + 1);
			}
			free(tmp);
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
	if (argc >= 2)
		ft_maxlenoc(argv + 1, argc - 1);
	ft_putstr("\n");
	return (0);
}
