#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char s[20];
  printf("s: ");
  fgets(s, sizeof(s), stdin);
  if (s == NULL)
  {
    return 1;
  }

  // char *t = s; // copy by reference
  // char *t = malloc(5 * sizeof(char)); // Allocate memory for 5 characters
  char *t = malloc(strlen(s) + 1);
  if (t == NULL)
  { // Check if memory allocation was successful
    printf("Memory allocation failed\n");
    return 1;
  }

  // for (int i = 0, n = strlen(s) + 1; i < n; i++)
  // {
  //   t[i] = s[i];
  // }
  strcpy(t, s);

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  printf("s: %s", s);
  printf("t: %s", t);

  free(t); // Free the allocated memory
  return 0;
}

char *get_string(const char *prompt)
{
  printf("%s", prompt);

  // Allocate an initial buffer size
  size_t buffer_size = 100;
  char *str = malloc(buffer_size);

  if (str == NULL)
  {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  // Read a line of input
  if (fgets(str, buffer_size, stdin) != NULL)
  {
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Resize the buffer to the actual size needed
    str = realloc(str, strlen(str) + 1);
  }

  return str;
}