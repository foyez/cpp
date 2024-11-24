#include <stdbool.h>
#include <stdio.h>

const int N = 4;

bool is_valid(int matrix[N][N], int row, int col, int value)
{
  int i = 0;
  while (i < N)
  {
    if (matrix[row][i] == value || matrix[i][col] == value)
    {
      return false;
    }
    i++;
  }
  return true;
}

int count_visible(int *line, int size, bool reverse)
{
  int max_height = 0;
  int visible_count = 0;

  for (int i = 0; i < size; i++)
  {
    int current_height = reverse ? line[size - 1 - i] : line[i];
    if (current_height > max_height)
    {
      max_height = current_height;
      visible_count++;
    }
  }

  return visible_count;
}

bool check_views(int grid[N][N], int views[4][N])
{
  int temp[N]; // Temporary array to hold a row or column

  // Check top and bottom views (columns)
  for (int col = 0; col < N; col++)
  {
    // Extract column into temp array
    for (int row = 0; row < N; row++)
    {
      temp[row] = grid[row][col];
    }

    // Validate top view
    if (count_visible(temp, N, false) != views[0][col])
    {
      return false;
    }

    // Validate bottom view
    if (count_visible(temp, N, true) != views[1][col])
    {
      return false;
    }
  }

  // Check left and right views (rows)
  for (int row = 0; row < N; row++)
  {
    // Validate left view
    if (count_visible(grid[row], N, false) != views[2][row])
    {
      return false;
    }

    // Validate right view
    if (count_visible(grid[row], N, true) != views[3][row])
    {
      return false;
    }
  }

  return true;
}

bool solve(int matrix[N][N], int row, int col)
{
  int views[4][N] = {
      {4, 3, 2, 1},
      {1, 2, 2, 2},
      {4, 3, 2, 1},
      {1, 2, 2, 2}};

  // If we reach the last row and column, the matrix is complete
  if (row == N)
  {
    // if (!check_views(matrix, views))
    // {
    //   return false;
    // }
    return true;
  }
  // Move to the next row if we've finished this row
  if (col == N)
  {
    return solve(matrix, row + 1, 0);
  }
  int value;
  while (value <= N)
  {
    if (is_valid(matrix, row, col, value))
    {
      matrix[row][col] = value;

      if (solve(matrix, row, col + 1))
      {
        return true;
      }
      matrix[row][col] = 0;
    }
    value++;
  }
  return false;
}

void print_matrix(int matrix[N][N])
{
  int i = 0;
  int j;
  while (i < N)
  {
    j = 0;
    while (j < N)
    {
      printf("%d ", matrix[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

int main()
{
  int matrix[N][N] = {0};

  if (solve(matrix, 0, 0))
  {
    print_matrix(matrix);
  }
  else
  {
    printf("No solution exists.");
  }
  return 0;
}