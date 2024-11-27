#include <stdio.h>
#include <stdlib.h>

// memory leak: allocated memory is not freed
void memory_leak(void)
{
  int *leaky_ptr;

  leaky_ptr = malloc(10 * sizeof(int));
  // No free() call here, causing a memory leak
}

// heap buffer overflow: writing beyond allocated memory
void buffer_overflow(void)
{
  int *arr;

  arr = malloc(5 * sizeof(int));
  for (int i = 0; i <= 5; i++) // Off-by-one error (buffer overflow)
  {
    arr[i] = i;
  }
  free(arr);
}

void leaks(void)
{
  system("leaks a.out");
}

int main(void)
{
  // atexit(leaks);
  memory_leak();
  printf("Press Enter to continue...");
  getchar();
  buffer_overflow();
  return (0);
}