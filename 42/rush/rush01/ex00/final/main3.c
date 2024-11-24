#include <stdio.h>
#include <stdlib.h>

// Custom atoi implementation
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

// Function to find the next token (number) in the string
char *next_token(char *str, char **end_ptr)
{
  while (*str == ' ')
    str++; // Skip leading spaces

  if (*str == '\0')
    return NULL; // No more tokens

  *end_ptr = str;
  while (**end_ptr >= '0' && **end_ptr <= '9')
    (*end_ptr)++; // Find end of the number

  return str;
}

// Main parse_input function
int *parse_input(char *input, int *size)
{
  int count = 0; // Count of numbers
  char *current = input;
  char *end_ptr = NULL;

  // First pass: Count the numbers to determine SIZE
  while ((current = next_token(current, &end_ptr)))
  {
    count++;
    current = end_ptr;
  }

  if (count % 4 != 0)
    return NULL; // Ensure count is divisible by 4
  *size = count / 4;

  // Allocate memory for parsed values
  int *values = malloc(count * sizeof(int));
  if (!values)
    return NULL;

  // Second pass: Parse the numbers into the values array
  current = input;
  int i = 0;
  while ((current = next_token(current, &end_ptr)))
  {
    int num = ft_atoi(current);
    if (num < 1 || num > 4)
    {
      free(values);
      return NULL;
    }
    values[i++] = num;
    current = end_ptr;
  }

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

  int size; // Variable to store the calculated SIZE
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
