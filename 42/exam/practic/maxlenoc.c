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

void	free_res(char *res)
{
	if (res)
		free(res);
}

void	free_tmp(char *tmp)
{
	if (tmp)
		free(tmp);
}

void	str_maxlenoc(int argc, char **argv)
{
	char	*first_str;
	int		first_len;
	char	*result;
	char	*tmp;
	int		max_len;
	int		len;
	int		start;

	first_str = argv[1];
	first_len = ft_strlen(first_str);
	result = NULL;
	max_len = 0;
	len = 0;
	while (++len <= first_len)
	{
		start = -1;
		while (++start <= first_len - len)
		{
			tmp = (char *)malloc(sizeof(char) * (len + 1));
			ft_strncpy(tmp, &first_str[start], len);
			tmp[len] = '\0';
			if (!is_common_substring(tmp, argv + 1, argc - 1))
			{
				free_tmp(tmp);
				continue ;
			}
			if (len > max_len)
			{
				max_len = len;
				if (result)
					free(result);
				result = (char *)malloc((len + 1) * sizeof(char));
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
	if (argc >= 2)
		str_maxlenoc(argc, argv);
	write(1, "\n", 1);
	return (0);
}
