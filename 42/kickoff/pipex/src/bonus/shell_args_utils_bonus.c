/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_args_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:13:48 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/01 17:37:17 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*resize_buffer(char *old, int old_cap, int new_cap)
{
	char	*new_buf;
	int		i;

	new_buf = malloc(new_cap + 1);
	if (!new_buf)
	{
		free(old);
		return (NULL);
	}
	i = -1;
	while (++i < old_cap)
		new_buf[i] = old[i];
	free(old);
	return (new_buf);
}

void	free_tokenizer(t_tokenizer *t)
{
	int	i;

	if (t->tokens)
	{
		i = 0;
		while (i < t->token_count)
			free(t->tokens[i++]);
		free(t->tokens);
	}
	free(t->token);
}

int	append_token(t_tokenizer *t)
{
	char	*new_token;

	t->token[t->token_len] = '\0';
	new_token = ft_strdup(t->token);
	if (!new_token)
		return (0);
	t->tokens[t->token_count++] = new_token;
	t->token_len = 0;
	return (1);
}

int	append_char(t_tokenizer *t, char c)
{
	if (t->token_len + 1 >= t->cap)
	{
		t->token = resize_buffer(t->token, t->token_len, t->cap * 2);
		if (!t->token)
			return (0);
		t->cap *= 2;
	}
	t->token[t->token_len++] = c;
	return (1);
}
