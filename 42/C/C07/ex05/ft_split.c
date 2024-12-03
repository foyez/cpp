#include <stdlib.h>

int	ft_is_separator(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_separator(charset, *str))
			str++;
		if (*str && !ft_is_separator(charset, *str))
		{
			count++;
			while (*str && !ft_is_separator(charset, *str))
				str++;
		}
	}
	return (count);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_separator(charset, str[i]))
		i++;
	return (i);
}

char	*ft_malloc_word(char *str, char *charset)
{
	char	*word;
	int		wordlen;
	int		i;

	wordlen = ft_wordlen(str, charset);
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		word[i] = str[i];
		i++;
	}
	word[wordlen] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_separator(charset, *str))
			str++;
		if (*str && !ft_is_separator(charset, *str))
		{
			arr[i] = ft_malloc_word(str, charset);
			if (!arr[i])
			{
				free(arr);
				return (NULL);
			}
			i++;
			while (*str && !ft_is_separator(charset, *str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
#include <stdio.h>

int	main(void)
{
	char	**arr;
	int		i;

	// arr = ft_split("", "");
	arr = ft_split("hello", "");
	// arr = ft_split("aaabbbaaaccc", "ab");
	// arr = ft_split("hello,,,,world", ",");
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
