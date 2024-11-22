#include <stdlib.h>

int len(long nb)
{
  int length = 0;
  if (nb <= 0)
    length++;
  while (nb != 0)
  {
    nb /= 10;
    length++;
  }
  return length;
}

char *ft_itoa(int nb)
{
  char *str;
  int length;
  long n;

  n = nb;
  length = len(n);
  str = (char *)malloc(sizeof(char) * (length + 1));
  str[length] = '\0';
  if (n == 0)
  {
    str[0] = '0';
    return str;
  }
  if (n < 0)
  {
    str[0] = '-';
    n = -n;
  }
  while (n > 0)
  {
    length--;
    str[length] = (n % 10) + '0';
    n /= 10;
  }
  return str;
}

#include <stdio.h>

int main(void)
{
  printf("%s\n", ft_itoa(-203));
  printf("%s\n", ft_itoa(-0));
  printf("%s\n", ft_itoa(2147483647));
  printf("%s\n", ft_itoa(-2147483648));
  return (0);
}