#ifndef TEST_FT_PRINTF_H
# define TEST_FT_PRINTF_H

# include "../include/ft_printf.h"
# include <stdio.h>
# include <string.h>

#define TEST(name, format, ...)                                             \
{                                                                       \
	printf("🚀 Test: %s 🚀\n", name);                                   \
																		\
	fflush(stdout);                                                     \
	int saved_stdout = dup(STDOUT_FILENO);                              \
	FILE *ft_tmp = tmpfile();                                           \
	int ft_fd = fileno(ft_tmp);                                         \
	dup2(ft_fd, STDOUT_FILENO);                                         \
	int ft_result = ft_printf(format, ##__VA_ARGS__);                  \
	fflush(stdout);                                                     \
	fseek(ft_tmp, 0, SEEK_END);                                         \
	long ft_length = ftell(ft_tmp);                                     \
	fseek(ft_tmp, 0, SEEK_SET);                                         \
	char *ft_output = malloc(ft_length + 1);                           \
	if (ft_output) {                                                    \
		fread(ft_output, 1, ft_length, ft_tmp);                         \
		ft_output[ft_length] = '\0';                                    \
	} else {                                                            \
		ft_output = NULL;                                               \
		ft_length = 0;                                                  \
	}                                                                   \
	fclose(ft_tmp);                                                     \
	dup2(saved_stdout, STDOUT_FILENO);                                  \
	close(saved_stdout);                                                \
																		\
	fflush(stdout);                                                     \
	saved_stdout = dup(STDOUT_FILENO);                                  \
	FILE *std_tmp = tmpfile();                                          \
	int std_fd = fileno(std_tmp);                                        \
	dup2(std_fd, STDOUT_FILENO);                                        \
	int std_result = printf(format, ##__VA_ARGS__);                     \
	fflush(stdout);                                                     \
	fseek(std_tmp, 0, SEEK_END);                                        \
	long std_length = ftell(std_tmp);                                   \
	fseek(std_tmp, 0, SEEK_SET);                                        \
	char *std_output = malloc(std_length + 1);                          \
	if (std_output) {                                                   \
		fread(std_output, 1, std_length, std_tmp);                      \
		std_output[std_length] = '\0';                                  \
	} else {                                                            \
		std_output = NULL;                                              \
		std_length = 0;                                                 \
	}                                                                   \
	fclose(std_tmp);                                                    \
	dup2(saved_stdout, STDOUT_FILENO);                                  \
	close(saved_stdout);                                                \
																		\
	printf("(ft_printf) -> Output: \"");                               \
	if (ft_output) {                                                    \
		fwrite(ft_output, 1, ft_length, stdout);                        \
	} else {                                                            \
		printf("(null)");                                               \
	}                                                                   \
	printf("\", Return: %d\n", ft_result);                              \
	printf("(printf)    -> Output: \"");                               \
	if (std_output) {                                                   \
		fwrite(std_output, 1, std_length, stdout);                      \
	} else {                                                            \
		printf("(null)");                                               \
	}                                                                   \
	printf("\", Return: %d\n", std_result);                             \
																		\
	int return_diff = (ft_result != std_result);                        \
	int output_diff = 0;                                                \
	if (ft_output && std_output) {                                      \
		if (ft_length != std_length) {                                 \
			output_diff = 1;                                            \
		} else {                                                        \
			output_diff = memcmp(ft_output, std_output, ft_length) != 0;\
		}                                                               \
	} else if (ft_output != std_output) {                               \
		output_diff = 1;                                                \
	}                                                                   \
																		\
	if (return_diff || output_diff) {                                   \
		printf(" [FAIL] ❌\n");                                         \
		if (output_diff) {                                              \
			printf("➡️ Outputs differ!\n");                        \
		}                                                               \
		if (return_diff) {                                              \
			printf("➡️ Return values differ!\n");                  \
		}                                                               \
	} else {                                                            \
		printf(" [PASS] ✅\n");                                         \
	}                                                                   \
																		\
	free(ft_output);                                                    \
	free(std_output);                                                   \
	printf("\n");                                                       \
}

#endif // TEST_FT_PRINTF_H
