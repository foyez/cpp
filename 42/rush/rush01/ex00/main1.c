#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

// Function to print the matrix
void printMatrix(int mat[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      char c = mat[i][j] + '0';
      write(1, &c, 1);
      if (j < N - 1)
        write(1, " ", 1);
    }
    write(1, "\n", 1);
  }
}

// Check visibility from a given direction dynamically
bool checkVisibility(int *line, int clue)
{
  int count = 0, maxHeight = 0;
  for (int i = 0; i < N; i++)
  {
    if (line[i] > maxHeight)
    {
      maxHeight = line[i];
      count++;
    }
  }
  return clue == count;
}

// Validate visibility for a given row or column
bool isValidView(int mat[N][N], int clues[4][N], int row, int col)
{
  int temp[N];

  // Check row visibility from left
  if (col == N - 1)
  {
    for (int i = 0; i < N; i++)
      temp[i] = mat[row][i];
    if (!checkVisibility(temp, clues[2][row]))
      return false;
  }

  // Check row visibility from right
  if (col == N - 1)
  {
    for (int i = 0; i < N; i++)
      temp[i] = mat[row][N - i - 1];
    if (!checkVisibility(temp, clues[3][row]))
      return false;
  }

  // Check column visibility from top
  if (row == N - 1)
  {
    for (int i = 0; i < N; i++)
      temp[i] = mat[i][col];
    if (!checkVisibility(temp, clues[0][col]))
      return false;
  }

  // Check column visibility from bottom
  if (row == N - 1)
  {
    for (int i = 0; i < N; i++)
      temp[i] = mat[N - i - 1][col];
    if (!checkVisibility(temp, clues[1][col]))
      return false;
  }

  return true;
}

// Check if placing value at mat[row][col] is safe
bool isSafe(int mat[N][N], int row, int col, int value)
{
  for (int i = 0; i < N; i++)
  {
    if (mat[row][i] == value || mat[i][col] == value)
    {
      return false;
    }
  }
  return true;
}

// Backtracking function to solve the puzzle
bool solve(int mat[N][N], int clues[4][N], int row, int col)
{
  if (row == N)
  {
    return true;
  }

  if (col == N)
  {
    return solve(mat, clues, row + 1, 0);
  }

  for (int value = 1; value <= N; value++)
  {
    if (isSafe(mat, row, col, value))
    {
      mat[row][col] = value;

      if (isValidView(mat, clues, row, col) && solve(mat, clues, row, col + 1))
      {
        return true;
      }

      mat[row][col] = 0; // Backtrack
    }
  }

  return false;
}

int main()
{
  int mat[N][N] = {0};

  // int clues[4][N] = {
  //     {4, 3, 2, 1}, // column up
  //     {1, 2, 2, 2}, // column down
  //     {4, 3, 2, 1}, // row left
  //     {1, 2, 2, 2}  // row right
  // };

  int clues[4][N] = {
      {3, 3, 1, 2}, // column up
      {1, 2, 2, 3}, // column down
      {2, 3, 2, 1}, // row left
      {2, 1, 2, 3}  // row right
  };

  if (solve(mat, clues, 0, 0))
  {
    printMatrix(mat);
  }
  else
  {
    write(1, "Error\n", 6);
  }

  return 0;
}
