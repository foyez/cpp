int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return (i);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
  unsigned int len;
  unsigned int i;

  len = ft_strlen(src);
  i = 0;
  if (size == 0)
  {
    return (len);
  }
  while (src[i] != '\0' && i < size - 1)
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (len);
}

#include <stdio.h>

int main(void)
{
  char src[] = "World";
  char dest[] = "Hello ";
  printf("%d | %s", ft_strlcpy(dest, src, 5), dest);
  return (0);
}