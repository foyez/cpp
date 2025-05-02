#include <stdlib.h>

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int ft_count_words(char const *s)
{
	int count = 0;

	while (*s)
	{
		while (is_whitespace(*s))
			s++;
		if (*s)
			count++;
		while (*s && !is_whitespace(*s))
			s++;
	}
	return (count);
}

int ft_wordlen(char const *s)
{
	int len = 0;
	while (s[len] && !is_whitespace(s[len]))
		len++;
	return (len);
}

char *ft_allocate_word(char const *s)
{
	char *word;
	int len;
	int i;

	len = ft_wordlen(s);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void ft_free_split(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

char **ft_split(char const *s)
{
	int size = ft_count_words(s);
	char **arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	int i = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		if (*s)
		{
			arr[i] = ft_allocate_word(s);
			if (!arr[i])
			{
				ft_free_split(arr, i - 1);
				return (NULL);
			}
			i++;
		}
		while (*s && !is_whitespace(*s))
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

#include <stdio.h>

void	leaks(void)
{
	system("leaks a.out");
	// cc -fsanitize=address -Wall -Wextra -Werror -g ft_split.c
	// ./a.out | cat -e
}

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
