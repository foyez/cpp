#include <stdio.h>
#include <string.h>

int calculate_length(char array[]);

int main(void)
{
  char name[] = "Name";
  int n = strlen(name);
  printf("%i\n", n);
  printf("%i\n", calculate_length(name));
}

int calculate_length(char array[])
{
  int n = 0;
  while (array[n] != '\0')
  {
    n++;
  }
  return n;
}