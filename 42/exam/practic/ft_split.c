#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	ft_count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_whitespace(*str))
			str++;
		if (*str && !ft_is_whitespace(*str))
		{
			count++;
			while (*str && !ft_is_whitespace(*str))
				str++;
		}
	}
	return (count);
}

int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_whitespace(str[i]))
		i++;
	return (i);
}

char	*ft_malloc_word(char *str)
{
	char	*word;
	int		wordlen;
	int		i;

	wordlen = ft_wordlen(str);
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

char	**ft_split(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_whitespace(*str))
			str++;
		if (*str && !ft_is_whitespace(*str))
		{
			arr[i] = ft_malloc_word(str);
			if (!arr[i])
			{
				free(arr);
				return (NULL);
			}
			i++;
			while (*str && !ft_is_whitespace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

void	leaks(void)
{
	system("leaks a.out");
	// cc -fsanitize=address -Wall -Wextra -Werror -g ft_split.c
	// ./a.out | cat -e
}

#include <stdio.h>

int	main(void)
{
	char	**arr;
	int		i;

	atexit(leaks);
	arr = ft_split("hello who 	are you?");
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]); // Free each word
		i++;
	}
	free(arr); // Free the array itself
	return (0);
}
