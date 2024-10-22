#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
  // Get size of grid
  int n = get_size();

  // Print grid of bricks
  print_grid(n);
}

int get_size(void)
{
  // const int n = 3;

  // int n;
  // printf("Size: ");
  // scanf("%d", &n);
  // while (n < 1)
  // {
  //   printf("Size: ");
  //   scanf("%d", &n);
  // }

  // Get size of grid
  int n;
  do
  {
    printf("Size: ");
    scanf("%d", &n);
  } while (n < 1);

  return n;
}

void print_grid(int n)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < n; c++)
    {
      printf("#");
    }
    printf("\n");
  }
}