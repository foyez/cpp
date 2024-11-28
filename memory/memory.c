#include <stdio.h>
#include <stdlib.h>

// BEST PRACTICES
// 1. Dynamic Memory Allocation
// 2. Check NULL after allocation
// 3. Use sizeof on the variable type, not the hardcoded size
// 4. After freeing a pointer, set it to NULL to prevent
// accidentally freeing it again

// CHECK MEMORY LEAKS
// AddressSanitizer: cc -fsanitize=address -g file.c

char *allocate_memory_buffer(void)
{
  char *buffer;

  buffer = malloc(sizeof(*buffer) * 10); // Safer than sizeof(char) * 10
  if (buffer == NULL)
  {
    fprintf(stderr, "Unable to allocate memory\n");
    // exit(1);
    return (NULL);
  }
  return (buffer);
}

int main(void)
{
  char *buffer;

  buffer = allocate_memory_buffer();
  if (!buffer)
    return (1);
  puts("Memory allocated");
  free(buffer);
  buffer = NULL;
  free(buffer);
  puts("Memory freed");
  return (0);
}
