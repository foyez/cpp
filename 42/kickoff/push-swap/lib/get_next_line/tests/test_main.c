/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:32 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 21:24:33 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("tests/test1.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line);
//     }
// 	line = get_next_line(fd);
// 	printf("%s", line);
//     free(line);

//     close(fd);
//     return (0);
// }
