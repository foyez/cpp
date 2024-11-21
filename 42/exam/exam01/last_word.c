#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

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

int is_tab_or_space(char c)
{
  if (c == '\t' || c == 32)
  {
    return (1);
  }
  return (0);
}

void last_word(char *str)
{
  int n;
  int i;

  n = ft_strlen(str);
  i = n - 1;
  // skip tabs and spaces
  while (is_tab_or_space(str[i]) == 1)
  {
    i--;
  }

  while (i > 0)
  {
    if (is_tab_or_space(str[i]) == 1)
    {
      i++;
      break;
    }
    i--;
  }

  while (str[i] != '\0' && is_tab_or_space(str[i]) == 0)
  {
    ft_putchar(str[i]);
    i++;
  }
}

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    last_word(argv[1]);
  }
  ft_putchar('\n');
  return (0);
}