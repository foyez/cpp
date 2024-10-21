#include <stdio.h>

int main(void)
{
  int x;
  printf("What's x? ");
  scanf("%d", &x);

  int y;
  printf("What's y? ");
  scanf("%d", &y);

  if (x < y)
  {
    printf("%d is less than %d\n", x, y);
  }
  else if (x > y)
  {
    printf("%d is greater than %d\n", x, y);
  }
  else
  {
    printf("%d is equal to %d\n", x, y);
  }
}