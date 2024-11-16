void ft_putchar(char c);
void ft_print_row(int x, char left, char middle, char right);

void rush(int x, int y)
{
  int row;
  char back_slash;
  char forward_slash;
  char star;
  char space;

  if (x < 1 || y < 1)
  {
    return;
  }

  row = 1;
  back_slash = '\\';
  forward_slash = '/';
  star = '*';
  space = ' ';
  while (row <= y)
  {
    if (row == 1)
    {
      ft_print_row(x, forward_slash, star, back_slash);
    }
    else if (row == y)
    {
      ft_print_row(x, back_slash, star, forward_slash);
    }
    else
    {
      ft_print_row(x, star, space, star);
    }
    row++;
  }
}

void ft_print_row(int x, char left, char middle, char right)
{
  int col;

  col = 1;
  while (col <= x)
  {
    if (col == 1)
    {
      ft_putchar(left);
    }
    else if (col == x)
    {
      ft_putchar(right);
    }
    else
    {
      ft_putchar(middle);
    }
    col++;
  }
  ft_putchar('\n');
}