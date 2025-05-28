#include <stdio.h>
#include <stdlib.h>

// Memory leak: allocated memory is not freed
void memory_leak(void)
{
  int *leaky_ptr = malloc(10 * sizeof(int));
  // Memory not freed - leak!
}

// Heap buffer overflow: writing beyond allocated memory
void buffer_overflow(void)
{
  int *arr = malloc(5 * sizeof(int));
  for (int i = 0; i <= 5; i++) // Off-by-one error (buffer overflow)
  {
    arr[i] = i;
  }
  free(arr);
}

// Segmentation fault: accessing invalid memory
void segmentation_fault(void)
{
  int *ptr = NULL;
  *ptr = 42; // Dereferencing NULL causes segmentation fault
}

// Use-after-free: accessing memory after it's freed
void use_after_free(void)
{
  int *data = malloc(sizeof(int) * 4);
  data[0] = 100;
  free(data);
  data[0] = 200; // Writing to freed memory
}

// Double free: freeing already-freed memory
void double_free(void)
{
  int *data = malloc(sizeof(int) * 4);
  free(data);
  free(data); // Double free error
}

// Uninitialized memory read: using variables without initializing
void uninitialized_access(void)
{
  int *arr = malloc(sizeof(int) * 5);
  printf("Uninitialized value: %d\n", arr[3]); // Reading uninitialized memory
  free(arr);
}

void leaks(void)
{
  system("leaks a.out"); // macOS-specific memory leak checker
}

int main(void)
{
  atexit(leaks); // Uncomment for leak check on exit
  printf("Memory Leak:\n");
  memory_leak();
  getchar();

//   printf("Buffer Overflow:\n");
//   buffer_overflow();
//   getchar();

//   printf("Segmentation Fault:\n");
//   segmentation_fault(); // This will crash
//   getchar();

//   printf("Use After Free:\n");
//   use_after_free();
//   getchar();

//   printf("Double Free:\n");
//   double_free();
//   getchar();

//   printf("Uninitialized Access:\n");
//   uninitialized_access();
//   getchar();

  return 0;
}

// to run: cc -fsanitize=address -g memory_leaks.c && ./a.out
