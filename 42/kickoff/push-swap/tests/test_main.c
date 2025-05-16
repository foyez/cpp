/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:42 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 21:24:43 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	test_valid_input(void)
// {
// 	char	*argv1[] = {"1 2", "5", "7 3"};
// 	int		argc1;
// 	int		expected[] = {1, 2, 5, 7, 3};
// 	int		count;
// 	int		*arr;

// 	argc1 = 3;
// 	count = count_numbers(argv1, argc1);
// 	assert(count == 5);
// 	arr = malloc(sizeof(int) * count);
// 	assert(arr != NULL);
// 	assert(fill_numbers(argv1, argc1, arr) == 0);
// 	for (int i = 0; i < count; i++)
// 		assert(arr[i] == expected[i]);
// 	free(arr);
// 	printf("test_valid_input passed.\n");
// }

// void	test_invalid_character(void)
// {
// 	char	*argv2[] = {"12a", "5"};
// 	int		argc2;
// 	int		count;

// 	argc2 = 3;
// 	count = count_numbers(argv2, argc2);
// 	assert(count == -1);
// 	printf("test_invalid_character passed.\n");
// }

// void	test_only_sign(void)
// {
// 	char	*argv3[2] = {"+", "-"};
// 	int		argc3;
// 	int		count;

// 	argc3 = 2;
// 	count = count_numbers(argv3, argc3);
// 	assert(count == -1);
// 	printf("test_only_sign passed.\n");
// }

// void	test_overflow(void)
// {
// 	int	argc4;
// 	int	count;
// 	int	*arr;

// 	char *argv4[] = {"2147483648"}; // INT_MAX + 1
// 	argc4 = 1;
// 	count = count_numbers(argv4, argc4);
// 	assert(count == 1); // it still counts
// 	arr = malloc(sizeof(int) * count);
// 	assert(arr != NULL);
// 	assert(fill_numbers(argv4, argc4, arr) == -1);
// 	free(arr);
// 	printf("test_overflow passed.\n");
// }

// void	test_underflow(void)
// {
// 	int	argc5;
// 	int	count;
// 	int	*arr;

// 	char *argv5[] = {"-2147483649"}; // INT_MIN - 1
// 	argc5 = 1;
// 	count = count_numbers(argv5, argc5);
// 	assert(count == 1); // it still counts
// 	arr = malloc(sizeof(int) * count);
// 	assert(arr != NULL);
// 	assert(fill_numbers(argv5, argc5, arr) == -1);
// 	free(arr);
// 	printf("test_underflow passed.\n");
// }

// void	test_multiple_spaces(void)
// {
// 	char	*argv6[] = {"  1   23    456 "};
// 	int		argc6;
// 	int		expected[] = {1, 23, 456};
// 	int		count;
// 	int		*arr;

// 	argc6 = 1;
// 	count = count_numbers(argv6, argc6);
// 	assert(count == 3);
// 	arr = malloc(sizeof(int) * count);
// 	assert(arr != NULL);
// 	assert(fill_numbers(argv6, argc6, arr) == 0);
// 	for (int i = 0; i < count; i++)
// 		assert(arr[i] == expected[i]);
// 	free(arr);
// 	printf("test_multiple_spaces passed.\n");
// }

// void	test_duplicate(void)
// {
// 	int		argc7;
// 	int		count;
// 	int		*arr;
// 	char	*argv7[] = {"1 2", "2"};

// 	argc7 = 2;
// 	count = count_numbers(argv7, argc7);
// 	assert(count == 3); // it still counts
// 	arr = malloc(sizeof(int) * count);
// 	assert(arr != NULL);
// 	assert(fill_numbers(argv7, argc7, arr) == -1);
// 	free(arr);
// 	printf("test_duplicate passed.\n");
// }

// int	main(void)
// {
// 	test_valid_input();
// 	test_invalid_character();
// 	test_only_sign();
// 	test_overflow();
// 	test_underflow();
// 	test_multiple_spaces();
// 	test_duplicate();
// 	printf("\nAll tests passed.\n");
// 	return (0);
// }
