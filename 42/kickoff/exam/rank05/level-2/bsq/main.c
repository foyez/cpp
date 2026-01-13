#include "bsq.h"

// Helper: min of 3 numbers
static int min3(int a, int b, int c)
{
  int min = a;
  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}

// Helper: check if character is valid
static int is_valid_char(char c, char empty, char obs)
{
  return (c == empty || c == obs);
}

// Read and validate map from file
t_map *read_map(FILE *fp)
{
  t_map *m = malloc(sizeof(t_map));
  if (!m)
    return NULL;

  m->grid = NULL;

  // Read header
  if (fscanf(fp, "%d %c %c %c\n", &m->rows, &m->empty, &m->obstacle, &m->full) != 4)
  {
    free(m);
    return NULL;
  }

  // Validate header
  if (m->rows <= 0 || m->empty == m->obstacle || m->empty == m->full || m->obstacle == m->full)
  {
    free(m);
    return NULL;
  }

  // Allocate grid
  m->grid = malloc(sizeof(char *) * m->rows);
  if (!m->grid)
  {
    free(m);
    return NULL;
  }

  // Read map lines
  char *line = NULL;
  size_t len = 0;
  int row = 0;

  while (row < m->rows && getline(&line, &len, fp) != -1)
  {
    // Calculate line length (without newline)
    int line_len = 0;
    while (line[line_len] && line[line_len] != '\n')
      line_len++;

    // Set columns from first line
    if (row == 0)
    {
      m->cols = line_len;
      if (m->cols <= 0)
      {
        free(line);
        for (int i = 0; i < row; i++)
          free(m->grid[i]);
        free(m->grid);
        free(m);
        return NULL;
      }
    }

    // Validate line length
    if (line_len != m->cols)
    {
      free(line);
      for (int i = 0; i < row; i++)
        free(m->grid[i]);
      free(m->grid);
      free(m);
      return NULL;
    }

    // Allocate row
    m->grid[row] = malloc(m->cols + 1);
    if (!m->grid[row])
    {
      free(line);
      for (int i = 0; i < row; i++)
        free(m->grid[i]);
      free(m->grid);
      free(m);
      return NULL;
    }

    // Validate and copy characters
    for (int i = 0; i < line_len; i++)
    {
      if (!is_valid_char(line[i], m->empty, m->obstacle))
      {
        free(line);
        for (int j = 0; j <= row; j++)
          free(m->grid[j]);
        free(m->grid);
        free(m);
        return NULL;
      }
      m->grid[row][i] = line[i];
    }
    m->grid[row][line_len] = '\0';
    row++;
  }

  free(line);

  // Validate row count
  if (row != m->rows)
  {
    for (int i = 0; i < row; i++)
      free(m->grid[i]);
    free(m->grid);
    free(m);
    return NULL;
  }

  return m;
}

void free_map(t_map *map)
{
  if (!map)
    return;
  if (map->grid)
  {
    for (int i = 0; i < map->rows; i++)
    {
      if (map->grid[i])
        free(map->grid[i]);
    }
    free(map->grid);
  }
  free(map);
}

t_square find_biggest_square(t_map *m)
{
  t_square best = {0, 0, 0};

  if (!m || !m->grid)
    return best;

  // Allocate DP table
  int **dp = malloc(sizeof(int *) * m->rows);
  for (int i = 0; i < m->rows; i++)
  {
    dp[i] = calloc(m->cols, sizeof(int));
  }

  // Fill DP table
  for (int i = 0; i < m->rows; i++)
  {
    for (int j = 0; j < m->cols; j++)
    {
      if (m->grid[i][j] == m->obstacle)
      {
        dp[i][j] = 0;
      }
      else
      {
        if (i == 0 || j == 0)
        {
          dp[i][j] = 1;
        }
        else
        {
          // left, top, top-left diagonal
          dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }

        // Update best square (prefer top-left)
        if (dp[i][j] > best.size)
        {
          best.size = dp[i][j];
          best.row = i - dp[i][j] + 1;
          best.col = j - dp[i][j] + 1;
        }
        else if (dp[i][j] == best.size && best.size > 0)
        {
          int r = i - dp[i][j] + 1;
          int c = j - dp[i][j] + 1;
          if (r < best.row || (r == best.row && c < best.col))
          {
            best.row = r;
            best.col = c;
          }
        }
      }
    }
  }

  // Free DP table
  for (int i = 0; i < m->rows; i++)
  {
    free(dp[i]);
  }
  free(dp);

  return best;
}

void fill_and_print(t_map *m, t_square sq)
{
  // Fill square
  for (int i = sq.row; i < sq.row + sq.size; i++)
  {
    for (int j = sq.col; j < sq.col + sq.size; j++)
    {
      m->grid[i][j] = m->full;
    }
  }

  // Print map
  for (int i = 0; i < m->rows; i++)
  {
    fprintf(stdout, "%s\n", m->grid[i]);
  }
}

static void process_file(FILE *fp)
{
  t_map *map = read_map(fp);

  if (!map)
  {
    fprintf(stderr, "map error\n");
    return;
  }

  t_square sq = find_biggest_square(map);
  fill_and_print(map, sq);
  free_map(map);
}

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    process_file(stdin);
    return 0;
  }

  for (int i = 1; i < argc; i++)
  {
    FILE *fp = fopen(argv[i], "r");
    if (!fp)
    {
      fprintf(stderr, "map error\n");
      continue;
    }

    process_file(fp);
    fclose(fp);

    if (i < argc - 1)
    {
      fprintf(stdout, "\n");
    }
  }

  return 0;
}

// Problem:
// Find the largest square that can fit on a map while avoiding obstacles,
// then fill it with a special character.

// Input Format
// First line: rows empty_char obstacle_char full_char
// Number of rows in the map
// Character representing empty space
// Character representing obstacle
// Character to fill the square with

// Input Example:
// 4 . o x
// . . . .
// . . . .
// . . o .
// . . . .

// Map:
// . . . .
// . . . .
// . . o .
// . . . .

// DP Table (step by step):

// After row 0:
// 1 1 1 1

// After row 1:
// 1 1 1 1
// 1 2 2 2

// After row 2:
// 1 1 1 1
// 1 2 2 2
// 1 2 0 1

// After row 3:
// 1 1 1 1
// 1 2 2 2
// 1 2 0 1
// 1 2 1 2

// Largest value: 2 (appears at multiple positions)
// First occurrence (top-left priority): position (0,1) creates a 2x2 square

// To run:
// ./a.out example_file.txt
// cat example_file.txt | ./a.out