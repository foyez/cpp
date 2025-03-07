#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_strlen(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i;
}

void ft_puterr(char *str)
{
  write(2, str, ft_strlen(str));
}