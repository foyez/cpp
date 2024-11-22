#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int is_present(char *str, char c, int pos)
{
  int i;

  i = 0;
  while (i < pos)
  {
    if (str[i] == c)
    {
      return (1);
    }
    i++;
  }
  return (0);
}

void inter(char *s1, char *s2)
{
  int i;
  int j;

  i = 0;
  while (s1[i] != '\0')
  {
    if (is_present(s1, s1[i], i))
    {
      i++;
      continue;
    }
    j = 0;
    while (s2[j] != '\0')
    {
      if (s1[i] == s2[j])
      {
        ft_putchar(s1[i]);
        break;
      }
      j++;
    }
    i++;
  }
}

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    inter(argv[1], argv[2]);
  }
  ft_putchar('\n');
  return (0);
}