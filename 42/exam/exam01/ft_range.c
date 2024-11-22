#include <stdlib.h>

int ft_tabs(int n)
{
  if (n < 0)
  {
    return -n;
  }
  return n;
}

int *ft_range(int start, int end)
{
  int size;
  int *range;
  int i;

  size = ft_tabs(end - start) + 1;
  range = (int *)malloc(sizeof(int) * size);
  if (!range)
    return NULL;
  i = 0;
  while (i < size)
  {
    if (start <= end)
    {
      range[i] = start + i;
    }
    else
    {
      range[i] = start - i;
    }
    i++;
  }
  return range;
}

#include <stdio.h>

int main(void)
{
  int start = 4;
  int end = -4;
  int size = ft_tabs(end - start) + 1;
  int *arr = ft_range(start, end);
  if (!arr)
    return 1;
  for (int i = 0; i < size; i++)
  {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}