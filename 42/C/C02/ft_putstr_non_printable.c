#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_is_printable_char(char c)
{
  if (c >= 32 && c <= 126)
  {
    return (1);
  }
  return (0);
}

void ft_putnbr_hex(unsigned char c)
{
  const char *hex = "0123456789abcdef";

  ft_putchar('\\');
  ft_putchar('x');
  ft_putchar(hex[c / 16]);
  ft_putchar(hex[c % 16]);
}

void ft_putstr_non_printable(char *str)
{
  const char *hex = "0123456789abcdef";
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (ft_is_printable_char(str[i]) == 1)
    {
      ft_putchar(str[i]);
    }
    else
    {
      ft_putnbr_hex((unsigned char)str[i]);
    }
    i++;
  }
}

int main(void)
{
  char str[] = "Hello\tWorld\nNew Line!\x01\x02\x03";
  ft_putstr_non_printable(str);
  return (0);
}
