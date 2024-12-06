/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:43:41 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/04 21:35:35 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_includes(char *str, char to_find)
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
		while (*str && ft_includes(charset, *str))
			str++;
		if (*str && !ft_includes(charset, *str))
		{
			count++;
			while (*str && !ft_includes(charset, *str))
				str++;
		}
	}
	return (count);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_includes(charset, str[i]))
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
		return (0);
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
		return (0);
	while (*str)
	{
		while (*str && ft_includes(charset, *str))
			str++;
		if (*str && !ft_includes(charset, *str))
		{
			arr[i] = ft_malloc_word(str, charset);
			if (!arr[i++])
				return (0);
			while (*str && !ft_includes(charset, *str))
				str++;
		}
	}
	arr[i] = 0;
	return (arr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	**arr;
// 	int		i;

// 	// arr = ft_split("", "");
// 	// arr = ft_split("hello", "");
// 	arr = ft_split("aaabbbaaaccc", "ab");
// 	// arr = ft_split("hello,,,,world", ",");
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }
