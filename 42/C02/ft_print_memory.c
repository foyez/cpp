#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(const char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}

void ft_putnbr_hex(unsigned char c)
{
  const char *hex = "012345678abcdef";

  ft_putchar(hex[c / 16]);
  ft_putchar(hex[c % 16]);
}

void *ft_print_memory(void *addr, unsigned int size)
{
  unsigned char *memory;
  int i;
  const char *hex = "012345678abcdef";

  memory = (unsigned char *)addr;
  i = 0;
  while (i < size)
  {
    unsigned long addr_num = (unsigned long)(memory + i);
    i += 16;
  }
}