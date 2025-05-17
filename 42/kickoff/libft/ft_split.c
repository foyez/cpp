/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:15:22 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/18 01:04:53 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char del)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == del)
			s++;
		if (*s)
			count++;
		while (*s && *s != del)
			s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char del)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != del)
		len++;
	return (len);
}

static char	*ft_allocate_word(char const *s, int len)
{
	char	*word;
	int		i;

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

static void	ft_free_split(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

/// @brief Allocates memory (using malloc(3)) and returns an
/// array of strings obtained by splitting ’s’ using
/// the character ’c’ as a delimiter. The array must
/// end with a NULL pointer.
/// @param s
/// @param delim
/// @return The array of new strings resulting from the split.
/// NULL if the allocation fails.
char	**ft_split(char const *s, char delim)
{
	int		wordlen;
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (ft_word_count(s, delim) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != delim)
		{
			wordlen = ft_wordlen(s, delim);
			arr[i] = ft_allocate_word(s, wordlen);
			if (!arr[i])
				return (ft_free_split(arr, i - 1), NULL);
			i++;
			s += wordlen;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
