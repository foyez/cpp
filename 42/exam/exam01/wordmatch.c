#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str, int len)
{
  write(1, str, len);
}

void ft_wdmatch(char *s1, char *s2)
{
  int i;
  int j;
  int length;

  i = 0;
  j = 0;
  length = 0;
  while (s1[i] != '\0')
  {
    while (s2[j] != '\0')
    {
      if (s1[i] == s2[j])
      {
        length++;
        break;
      }
      j++;
    }
    i++;
  }

  if (length == i)
  {
    ft_putstr(s1, length);
  }
}

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    ft_wdmatch(argv[1], argv[2]);
  }
  ft_putchar('\n');
  return (0);
}