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

int is_whitespace(char c)
{
  return (c == '\t' || c == 32);
}

void last_word(char *str)
{
  int n;
  int i;

  n = ft_strlen(str);
  i = n - 1;
  // skip tabs and spaces
  while (is_whitespace(str[i]))
  {
    i--;
  }

  while (i > 0)
  {
    if (is_whitespace(str[i]))
    {
      i++;
      break;
    }
    i--;
  }

  while (str[i] != '\0' && !is_whitespace(str[i]))
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