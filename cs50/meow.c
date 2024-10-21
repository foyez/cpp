#include <stdio.h>

int main(void)
{
  int i = 3;

  while (i > 0)
  {
    printf("meow\n");
    i--;
  }

  for (int i = 0; i < 3; i++)
  {
    printf("meow\n");
  }
}