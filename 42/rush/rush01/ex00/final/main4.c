#include <stdio.h>
#include <stdlib.h>

// Function to check if a character is a whitespace
int ft_is_whitespace(char c)
{
  return (c == ' ' || c == '\t' || c == '\n');
}

// Skip leading whitespace characters
char *ft_skip_whitespace(char *str)
{
  while (*str && ft_is_whitespace(*str))
    str++;
  return str;
}

// Skip non-whitespace characters (to find the end of a word)
char *ft_skip_non_whitespace(char *str)
{
  while (*str && !ft_is_whitespace(*str))
    str++;
  return str;
}

// Calculate the length of a word (until the first whitespace)
int ft_wordlen(char *str)
{
  int i = 0;
  while (str[i] && !ft_is_whitespace(str[i]))
    i++;
  return i;
}

// Count the number of words in a string
int ft_count_words(char *str)
{
  int count = 0;
  while (*str)
  {
    str = ft_skip_whitespace(str);
    if (*str && !ft_is_whitespace(*str))
    {
      count++;
      str = ft_skip_non_whitespace(str);
    }
  }
  return count;
}

// Allocate memory for a word and copy it into the newly allocated memory
char *ft_allocate_word(char *str)
{
  char *word;
  int i;

  int word_len = ft_wordlen(str);
  word = (char *)malloc(sizeof(char) * (word_len + 1));
  i = 0;
  while (i < word_len)
  {
    word[i] = str[i];
    i++;
  }
  word[word_len] = '\0';
  return word;
}

// Split a string into an array of words
char **ft_split(char *str)
{
  char **arr;
  int i = 0;

  arr = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
  while (*str)
  {
    str = ft_skip_whitespace(str);
    if (*str && !ft_is_whitespace(*str))
    {
      arr[i] = ft_allocate_word(str);
      i++;
      str = ft_skip_non_whitespace(str);
    }
  }
  arr[i] = NULL;
  return arr;
}

// Custom atoi function to convert string to integer
int ft_atoi(const char *str)
{
  int result = 0;
  while (*str >= '0' && *str <= '9')
  {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result;
}

// Parse the input and convert it to an array of integers
int *parse_input(char *input, int *size)
{
  int count = 0;
  int i = 0;

  // Split the input string into tokens (words)
  char **tokens = ft_split(input);

  // Count the number of tokens
  while (tokens[count])
  {
    count++;
  }

  // Check if the number of tokens is divisible by 4
  if (count % 4 != 0)
  {
    free(tokens);
    return NULL;
  }

  *size = count / 4;

  // Allocate memory for the parsed values
  int *values = (int *)malloc(count * sizeof(int));
  if (!values)
  {
    free(tokens);
    return NULL;
  }

  // First pass: Validate and store values
  for (i = 0; i < count; i++)
  {
    int num = ft_atoi(tokens[i]);
    if (num < 1 || num > *size)
    { // Replace 4 with *size (calculated size)
      free(values);
      free(tokens);
      return NULL;
    }
    values[i] = num;
  }

  // Free the tokens array since it's no longer needed
  free(tokens);

  return values;
}

// Main function to test the logic
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <input>\n", argv[0]);
    return 1;
  }

  int size;
  int *view_values = parse_input(argv[1], &size);
  if (!view_values)
  {
    printf("Error: Invalid input\n");
    return 1;
  }

  // Arrange view values into 4 arrays (top, bottom, left, right)
  int views[4][size];
  for (int i = 0; i < size; i++)
  {
    views[0][i] = view_values[i];            // Top
    views[1][i] = view_values[size + i];     // Bottom
    views[2][i] = view_values[size * 2 + i]; // Left
    views[3][i] = view_values[size * 3 + i]; // Right
  }

  free(view_values);

  // Print the arranged views for verification
  printf("Top: ");
  for (int i = 0; i < size; i++)
    printf("%d ", views[0][i]);
  printf("\n");

  printf("Bottom: ");
  for (int i = 0; i < size; i++)
    printf("%d ", views[1][i]);
  printf("\n");

  printf("Left: ");
  for (int i = 0; i < size; i++)
    printf("%d ", views[2][i]);
  printf("\n");

  printf("Right: ");
  for (int i = 0; i < size; i++)
    printf("%d ", views[3][i]);
  printf("\n");

  return 0;
}
