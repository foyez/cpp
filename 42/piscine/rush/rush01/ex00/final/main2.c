#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void ft_puterr(char *str);
int *parse_input(char *input);
char *ft_strtok(char *str, const char *delim);

#define N 2

// // 4x4
// int views41[4][N] = {
//     {4, 3, 2, 1}, // column up
//     {1, 2, 2, 2}, // column down
//     {4, 3, 2, 1}, // row left
//     {1, 2, 2, 2}  // row right
// };

// int views42[4][N] = {
//     {3, 3, 1, 2}, // column up
//     {1, 2, 2, 3}, // column down
//     {2, 3, 2, 1}, // row left
//     {2, 1, 2, 3}  // row right
// };

// // 5x5
// int views51[4][N] = {
//     {3, 2, 5, 3, 1}, // column up
//     {2, 2, 1, 2, 4}, // column down
//     {3, 2, 1, 4, 2}, // row left
//     {1, 2, 3, 2, 3}  // row right
// };

// // 6x6
// int views61[4][N] = {
//     {4, 2, 4, 2, 2, 1}, // column up
//     {2, 3, 1, 2, 3, 4}, // column down
//     {6, 2, 2, 4, 1, 2}, // row left
//     {1, 2, 3, 2, 3, 3}  // row right
// };

// // 7x7
// int views71[4][N] = {
//     {4, 2, 1, 2, 2, 4, 3}, // column up
//     {2, 3, 3, 3, 4, 3, 1}, // column down
//     {2, 2, 3, 3, 3, 1, 2}, // row left
//     {3, 5, 3, 2, 2, 4, 1}  // row right
// };

// int views72[4][N] = {
//     {2, 3, 2, 3, 1, 4, 3}, // column up
//     {2, 1, 4, 3, 4, 2, 2}, // column down
//     {3, 1, 2, 3, 5, 4, 2}, // row left
//     {2, 6, 3, 2, 2, 1, 3}  // row right
// };

// // 9x9
// int views91[4][N] = {
//     {1, 3, 2, 2, 3, 3, 4, 3, 3}, // column up
//     {5, 2, 4, 4, 2, 3, 3, 3, 1}, // column down
//     {1, 2, 3, 3, 3, 2, 4, 3, 4}, // row left
//     {3, 3, 4, 3, 2, 3, 2, 4, 1}  // row right
// };

bool is_unique_value(int grid[N][N], int row, int col, int value)
{
  int i = 0;
  while (i < N)
  {
    if (grid[row][i] == value || grid[i][col] == value)
    {
      return false;
    }
    i++;
  }
  return true;
}

bool is_correct_amount_visible(int *line, int no_of_view, bool is_reverse)
{
  int count = 0;
  int max_height = 0;
  int i = 0;
  while (i < N)
  {
    int cur_height = is_reverse ? line[N - 1 - i] : line[i];
    if (cur_height == 0)
    {
      break;
    }
    if (cur_height > max_height)
    {
      max_height = cur_height;
      count++;
    }
    i++;
  }
  return count <= no_of_view;
}

bool is_valid_view(int grid[N][N], int views[4][N], int row, int col)
{
  static int line[N];
  int i;
  if (row == N - 1)
  {
    i = 0;
    while (i < N)
    {
      line[i] = grid[i][col];
      i++;
    }
    if (!is_correct_amount_visible(line, views[0][col], false))
    {
      return false;
    }
    if (!is_correct_amount_visible(line, views[1][col], true))
    {
      return false;
    }
  }

  if (col == N - 1)
  {
    if (!is_correct_amount_visible(grid[row], views[2][row], false))
    {
      return false;
    }
    if (!is_correct_amount_visible(grid[row], views[3][row], true))
    {
      return false;
    }
  }

  return true;
}

bool solve(int grid[N][N], int views[4][N], int row, int col)
{
  if (row == N)
  {
    return true;
  }
  if (col == N)
  {
    return solve(grid, views, row + 1, 0);
  }
  int value = 1;
  while (value <= N)
  {
    if (is_unique_value(grid, row, col, value))
    {
      grid[row][col] = value;
      if (is_valid_view(grid, views, row, col) && solve(grid, views, row, col + 1))
      {
        return true;
      }
      grid[row][col] = 0;
    }
    value++;
  }
  return false;
}

void print_grid(int grid[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      char c = grid[i][j] + '0';
      write(1, &c, 1);
      if (j < N - 1)
        write(1, " ", 1);
    }
    write(1, "\n", 1);
  }
}

bool is_valid_constraints(int views[4][N])
{
  int i = 0;
  while (i < N)
  {
    if (views[0][i] + views[1][i] > N + 1 || // Column constraints
        views[2][i] + views[3][i] > N + 1)   // Row constraints
    {
      return false;
    }
    i++;
  }
  return true;
}

int main(int argc, char **argv)
{
  int grid[N][N] = {0};

  if (argc != 2)
  {
    ft_puterr("Error 1\n");
    return 1;
  }
  int *view_values = parse_input(argv[1]);
  if (!view_values)
  {
    ft_puterr("Error 2\n");
    return 1;
  }

  int views[4][N];
  for (int i = 0; i < N; i++)
  {
    views[0][i] = view_values[i];         // Top
    views[1][i] = view_values[N + i];     // Bottom
    views[2][i] = view_values[N * 2 + i]; // Left
    views[3][i] = view_values[N * 3 + i]; // Right
  }

  free(view_values);

  // if (!is_valid_constraints(views61))
  // {
  //   ft_puterr("Error: Invalid constraints\n");
  //   return 1;
  // }

  print_grid(views);

  // if (solve(grid, views61, 0, 0))
  // {
  //   print_grid(grid);
  // }
  // else
  // {
  //   ft_puterr("Error\n");
  // }

  return 0;
}