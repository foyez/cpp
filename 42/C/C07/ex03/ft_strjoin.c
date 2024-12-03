#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_totallen(char **strs, int size, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*cur;
	int		len;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	len = ft_str_totallen(strs, size, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	cur = str;
	i = 0;
	while (i < size)
	{
		ft_strcpy(cur, strs[i]);
		cur += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(cur, sep);
			cur += ft_strlen(sep);
		}
		i++;
	}
	*cur = '\0';
	return (str);
}

#include <stdio.h>

int	main(void)
{
	int		size;
	char	**strs;
	char	*sep;
	char	*res;

	size = 3;
	sep = ", ";
	strs = (char **)malloc(sizeof(char *) * size);
	if (!strs)
		return (1);
	strs[0] = "Hello";
	strs[1] = "How are you?";
	strs[2] = "Goodbye";
	res = ft_strjoin(size, strs, sep);
	if (res)
	{
		printf("%s\n", res);
	}
	free(strs);
	return (0);
}
