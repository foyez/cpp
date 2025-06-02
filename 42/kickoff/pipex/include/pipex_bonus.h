/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:56:56 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/02 16:34:08 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

typedef struct s_pipex
{
	int				cmd_cnt;
	int				pipefds[2][2];
	int				read_pipe;
	int				write_pipe;
	int				fd_in;
	int				fd_out;
	int				wstatus;
	int				cmd_start;
	pid_t			last_pid;
	pid_t			pid;
	pid_t			waited_pid;
}					t_pipex;

typedef enum e_token_state
{
	NORMAL,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ESCAPED
}					t_token_state;

typedef struct s_tokenizer
{
	char			**tokens;
	int				token_count;
	char			*token;
	int				token_len;
	int				cap;
	t_token_state	state;
	t_token_state	prev_state;
	int				status;
}					t_tokenizer;

char				**split_shell_args(const char *cmd);
void				pipex_perror(const char *context);
char				*get_cmd_path(const char *cmd, char **envp);
void				childprocess(int i, char *cmd, t_pipex *p, char **envp);
int					waitforchildren(t_pipex *p);
int					parentprocess(t_pipex *p, char **argv, char **envp);
void				read_heredoc_input(const char *limiter, int *fd_in);
int					open_file(const char *filepath, int mode);
// utils
void				free_args(void **args);
void				close_files(int fd_in, int fd_out);
void				close_pipe_if(int pipefd[2], int condition);
void				exit_with_errno(void);
void				ft_usage_warning(const char *cmd, int is_here_doc);
void				ft_not_found_err(const char *cmd);
char				*resize_buffer(char *old, int old_cap, int new_cap);
void				free_tokenizer(t_tokenizer *t);
int					append_token(t_tokenizer *t);
int					append_char(t_tokenizer *t, char c);

#endif
