#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void ft_puterr(char *str);

#define N 7

// 4x4
int views41[4][N] = {
    {4, 3, 2, 1}, // column up
    {1, 2, 2, 2}, // column down
    {4, 3, 2, 1}, // row left
    {1, 2, 2, 2}  // row right
};

int views42[4][N] = {
    {3, 3, 1, 2}, // column up
    {1, 2, 2, 3}, // column down
    {2, 3, 2, 1}, // row left
    {2, 1, 2, 3}  // row right
};

// 5x5
int views51[4][N] = {
    {3, 2, 5, 3, 1}, // column up
    {2, 2, 1, 2, 4}, // column down
    {3, 2, 1, 4, 2}, // row left
    {1, 2, 3, 2, 3}  // row right
};

// 6x6
int views61[4][N] = {
    {4, 2, 4, 2, 2, 1}, // column up
    {2, 3, 1, 2, 3, 4}, // column down
    {6, 2, 2, 4, 1, 2}, // row left
    {1, 2, 3, 2, 3, 3}  // row right
};

// 7x7
int views71[4][N] = {
    {4, 2, 1, 2, 2, 4, 3}, // column up
    {2, 3, 3, 3, 4, 3, 1}, // column down
    {2, 2, 3, 3, 3, 1, 2}, // row left
    {3, 5, 3, 2, 2, 4, 1}  // row right
};

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
    if (cur_height > max_height)
    {
      max_height = cur_height;
      count++;
    }
    i++;
  }
  return no_of_view == count;
}

bool is_valid_view(int grid[N][N], int views[4][N], int row, int col)
{
  int line[N];
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

int main()
{
  int grid[N][N] = {0};

  if (solve(grid, views71, 0, 0))
  {
    print_grid(grid);
  }
  else
  {
    write(1, "Error\n", 6);
  }

  return 0;
}