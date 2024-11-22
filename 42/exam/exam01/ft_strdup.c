#include <stdlib.h>

int ft_strlen(char *str)
{
  int len = 0;
  while (str[len])
    len++;
  return len;
}

char *ft_strdup(char *src)
{
  int len = ft_strlen(src);
  char *s = (char *)malloc(sizeof(char) * (len + 1));
  s[len] = '\0';
  while (len >= 0)
  {
    s[len] = src[len];
    len--;
  }
  return s;
}

#include <stdio.h>

int main()
{
  printf("%s\n", ft_strdup("hello"));
  return 0;
}