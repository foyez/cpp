int ft_strcmp(char *s1, char *s2)
{
  int i = 0;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
  {
    i++;
  }
  return (s1[i] - s2[i]);
}

#include <stdio.h>

int main(void)
{
  char s1[] = "hi";
  char s2[] = "hello";
  printf("%d\n", ft_strcmp(s1, s2));
  return (0);
}