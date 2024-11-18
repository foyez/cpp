// 9 - 13 control characters

int ascii_to_num(char ascii)
{
  return ascii - '0';
}

int ft_atoi(const char *str)
{
  int i;
  int sign;
  int res;
  const int space = 32;

  i = 0;
  sign = 1;
  res = 0;

  while (str[i] == space || (str[i] >= 9 && str[i] <= 13))
  {
    i++;
  }

  if (str[i] == '-')
  {
    sign = -1;
    i++;
  }
  else if (str[i] == '+')
  {
    i++;
  }

  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
  {
    res *= 10;
    res += ascii_to_num(str[i]);
    i++;
  }
  return (res * sign);
}

#include <stdio.h>

int main(void)
{
  printf("%d\n", ft_atoi("-40"));
  printf("%d\n", ft_atoi("+40"));
  printf("%d\n", ft_atoi("8n40"));
  return (0);
}