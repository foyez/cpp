#include <stdlib.h>
#include <stdbool.h>

void ft_putchar(char c);

#define N 2

int ft_atoi(const char *str)
{
  int num = 0;
  while (*str)
  {
    if (*str < '0' || *str > '9')
    {
      return -1;
    }
    num *= 10;
    num += (*str - '0');
    str++;
  }
  return num;
}

int is_delim(char c, const char *delim)
{
  while (*delim)
  {
    if (c == *delim)
    {
      return 1;
    }
    delim++;
  }
  return 0;
}

char *ft_strtok(char *str, const char *delim)
{
  static char *input = NULL;
  if (str != NULL)
  {
    input = str;
  }

  if (input == NULL || *input == '\0')
  {
    ft_putchar('1');
    return NULL;
  }

  while (*input && is_delim(*input, delim))
  {
    input++;
  }

  if (*input == '\0')
  {
    ft_putchar('1');
    return NULL;
  }

  char *token_start = input;

  while (*input && !is_delim(*input, delim))
  {
    input++;
  }

  if (*input)
  {
    *input = '\0';
    input++;
  }

  return token_start;
}

int *parse_input(char *input)
{
  int *values = malloc(sizeof(int) * (N * 4));
  if (!values)
    return NULL;
  char *token = ft_strtok(input, " ");
  int i = 0;
  while (token)
  {
    int num = ft_atoi(token);
    if (num < 1 || num > N)
    {
      free(values);
      return NULL;
    }
    values[i] = num;
    token = ft_strtok(NULL, " ");
    i++;
  }

  if (i != N * 4)
  {
    free(values);
    return NULL;
  }

  return values;
}