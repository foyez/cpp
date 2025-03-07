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

int	is_common_substr(char *substr, char **strs, int count)
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
	char	*firststr;
	int		firstlen;
	char	*result;
	char	*tmp;
	int		maxlen;
	int		substrlen;
	int		start;

	firststr = strs[0];
	firstlen = ft_strlen(firststr);
	result = NULL;
	maxlen = 0;
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
			// skiping first string
			if (!is_common_substr(tmp, strs + 1, len - 1))
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
		str_maxlenoc(argc - 1, argv + 1);
	ft_putstr("\n");
	return (0);
}
