/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell_args_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:15:56 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/01 17:37:22 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	handle_escaped_state(t_tokenizer *t, char c)
{
	if (c == '\0')
		return (2);
	if (!append_char(t, c))
		return (0);
	t->state = t->prev_state;
	return (1);
}

static int	handle_normal_state(t_tokenizer *t, char c)
{
	if (c == '\'')
		t->state = SINGLE_QUOTE;
	else if (c == '"')
		t->state = DOUBLE_QUOTE;
	else if (c == ' ' || c == '\t' || c == '\0')
	{
		if (t->token_len > 0 && !append_token(t))
			return (0);
		if (c == '\0')
			return (2);
	}
	else if (!append_char(t, c))
		return (0);
	return (1);
}

static int	handle_quoted_state(t_tokenizer *t, char c, char quote_char)
{
	if (c == quote_char)
		t->state = NORMAL;
	else if (c == '\0')
		return (2);
	else if (!append_char(t, c))
		return (0);
	return (1);
}

static int	process_char(t_tokenizer *t, char c)
{
	int	status;

	if (t->state == ESCAPED)
		status = handle_escaped_state(t, c);
	else if (c == '\\')
	{
		t->prev_state = t->state;
		t->state = ESCAPED;
		status = 1;
	}
	else if (t->state == NORMAL)
		status = handle_normal_state(t, c);
	else if (t->state == SINGLE_QUOTE)
		status = handle_quoted_state(t, c, '\'');
	else
		status = handle_quoted_state(t, c, '"');
	return (status);
}

char	**split_shell_args(const char *cmd)
{
	t_tokenizer	t;
	int			i;

	if (!cmd || !*cmd)
		return (NULL);
	ft_memset(&t, 0, sizeof(t));
	t.tokens = (char **)malloc(sizeof(char *) * (ft_strlen(cmd) + 1));
	t.cap = 64;
	t.token = (char *)malloc(t.cap + 1);
	if (!t.tokens || !t.token)
		return (free(t.tokens), free(t.token), NULL);
	i = -1;
	while (cmd[++i])
	{
		t.status = process_char(&t, cmd[i]);
		if (t.status == 0 || t.status == 2)
			break ;
	}
	if (t.status != 0 && t.token_len > 0)
		t.status = append_token(&t);
	if (t.status == 0 || (cmd[i] == '\0' && t.state != NORMAL))
		return (free_tokenizer(&t), NULL);
	free(t.token);
	t.tokens[t.token_count] = NULL;
	return (t.tokens);
}

// int	main(void)
// {
// 	const char	*test_command = "\"H \\\"W\\\"\"";
// 	char		**tokens;

// 	printf("Testing command: %s\n", test_command);
// 	tokens = split_shell_args(test_command);
// 	if (!tokens)
// 	{
// 		printf("Error: Failed to parse command\n");
// 		return (1);
// 	}
// 	printf("Parsed tokens:\n");
// 	for (int i = 0; tokens[i] != NULL; i++)
// 	{
// 		printf("[%d] '%s'\n", i, tokens[i]);
// 	}
// 	// Expected output:
// 	// [0] 'sed "s/And/But/"'
// 	return (0);
// }
