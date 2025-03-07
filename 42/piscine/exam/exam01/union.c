#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_is_duplicate(char *s, int end, char c)
{
  int i = 0;
  while (i < end)
  {
    if (s[i] == c)
    {
      return (1);
    }
    i++;
  }
  return (0);
}

void ft_union(char *s1, char *s2)
{
  int i;
  int j;

  i = 0;
  while (s1[i] != '\0')
  {
    if (!ft_is_duplicate(s1, i, s1[i]))
    {
      ft_putchar(s1[i]);
    }
    i++;
  }

  j = 0;
  while (s2[j] != '\0')
  {
    if (!ft_is_duplicate(s1, i, s2[j]) && !ft_is_duplicate(s2, j, s2[j]))
    {
      ft_putchar(s2[j]);
    }
    j++;
  }
}

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    ft_union(argv[1], argv[2]);
  }
  ft_putchar('\n');
  return (0);
}