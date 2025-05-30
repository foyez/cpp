/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:23:22 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 19:31:00 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *lines)
{
	int		len;
	int		i;
	char	*str;

	if (!lines || lines[0] == '\0')
		return (NULL);
	len = 0;
	while (lines[len] && lines[len] != '\n')
		len++;
	if (lines[len] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = lines[i];
	str[i] = '\0';
	return (str);
}

static char	*trim_lines(const char *lines)
{
	int			i;
	const char	*s1;
	char		*res;

	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
		return (NULL);
	s1 = lines + i + 1;
	if (!s1)
		return (NULL);
	res = (char *)malloc(gnl_strlen(s1) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	init_acc_buffer(char *acc_buffer, size_t *acc_len,
		size_t acc_buf_size, char *leftover_buffer)
{
	acc_buffer[0] = '\0';
	*acc_len = 0;
	if (leftover_buffer[0])
	{
		gnl_strlcpy(acc_buffer, leftover_buffer, acc_buf_size);
		*acc_len = gnl_strlen(acc_buffer);
		leftover_buffer[0] = '\0';
	}
}

static char	*gnl_read_lines(int fd, char *lines, char *leftover_buffer)
{
	char	buffer[BUFFER_SIZE + 1];
	char	acc_buffer[BUFFER_SIZE + 1024 + 1];
	size_t	acc_len;
	int		bytes_read;

	init_acc_buffer(acc_buffer, &acc_len, sizeof(acc_buffer), leftover_buffer);
	bytes_read = 1;
	while (!gnl_strchr(acc_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(lines), NULL);
		buffer[bytes_read] = '\0';
		if (acc_len + bytes_read >= sizeof(acc_buffer) - 1)
		{
			lines = join_and_free(lines, acc_buffer);
			acc_buffer[0] = '\0';
			acc_len = 0;
		}
		gnl_strlcpy(acc_buffer + acc_len, buffer, sizeof(acc_buffer) - acc_len);
		acc_len += gnl_strlen(buffer);
	}
	if (acc_len > 0)
		lines = join_and_free(lines, acc_buffer);
	return (lines);
}

char	*get_next_line(int fd)
{
	char		*lines;
	char		*extracted_line;
	char		*remaining;
	static char	leftover_buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = NULL;
	lines = gnl_read_lines(fd, lines, leftover_buffer);
	if (!lines)
		return (NULL);
	extracted_line = extract_line(lines);
	if (!extracted_line)
		return (free(lines), NULL);
	remaining = trim_lines(lines);
	free(lines);
	if (remaining)
	{
		gnl_strlcpy(leftover_buffer, remaining, BUFFER_SIZE + 1);
		free(remaining);
	}
	else
		leftover_buffer[0] = '\0';
	return (extracted_line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("test1.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);  // Expecting lines from the file
//         free(line);  // Free after use
//     }
// 	line = get_next_line(fd);
// 	printf("%s", line);
//     free(line);

//     close(fd);
//     return (0);
// }
