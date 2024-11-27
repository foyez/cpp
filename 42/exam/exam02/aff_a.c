#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int main(int argc, char **argv)
{
  int i;
  char *str;

  i = 0;
  if (argc != 2)
  {
    ft_putchar('a');
  }
  else
  {
    str = argv[1];
    while (str[i] != '\0')
    {
      if (str[i] == 'a')
      {
        ft_putchar('a');
        break;
      }
      i++;
    }
  }
  ft_putchar('\n');
  return 0;
}