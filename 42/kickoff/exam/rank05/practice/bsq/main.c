#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
  int rows;
  int cols;
  char empty;
  char obstacle;
  char full;
  char **grid;
} t_map;

typedef struct s_square
{
  int size;
  int row;
  int col;
} t_square;

void ft_printerror()
{
  fprintf(stderr, "map error\n");
}

int is_valid_char(char c, char empty, char obs)
{
  return (c == empty || c == obs);
}

void free_map(t_map *m)
{
  if (!m)
    return;

  if (m->grid)
  {
    for (int i = 0; i < m->rows; i++)
      free(m->grid[i]);
    free(m->grid);
  }
  free(m);
}

void free_map_partial(t_map *m, int rows_alloc)
{
  if (!m)
    return;

  if (m->grid)
  {
    for (int i = 0; i < rows_alloc; i++)
      free(m->grid[i]);
    free(m->grid);
  }
  free(m);
}

t_map *read_map(FILE *f)
{
  t_map *m = malloc(sizeof(t_map));
  if (!m)
    return NULL;

  m->grid = NULL;

  // read header
  if (fscanf(f, "%d %c %c %c\n", &m->rows, &m->empty, &m->obstacle, &m->full) != 4)
  {
    free(m);
    return NULL;
  }

  // validate header
  if (m->rows <= 0 || m->empty == m->obstacle || m->empty == m->obstacle || m->obstacle == m->full)
  {
    free(m);
    return NULL;
  }

  // allocate grid
  m->grid = malloc(sizeof(char *) * m->rows);
  if (!m->grid)
  {
    free(m);
    return NULL;
  }

  // read map lines
  char *line = NULL;
  size_t len = 0;
  int row = 0;

  while (row < m->rows && getline(&line, &len, f) != -1)
  {
    // calc line length (without newline)
    int linelen = 0;
    while (line[linelen] && line[linelen] != '\n')
      linelen++;

    // set columns from first line
    if (row == 0)
    {
      m->cols = linelen;
      if (m->cols <= 0)
      {
        free(line);
        free_map_partial(m, row);
        return NULL;
      }
    }

    // validate line length
    if (linelen != m->cols)
    {
      free(line);
      free_map_partial(m, row);
      return NULL;
    }

    // allocate row
    m->grid[row] = malloc(m->cols + 1);
    if (!m->grid[row])
    {
      free(line);
      free_map_partial(m, row);
      return NULL;
    }

    // validate and copy characters
    for (int i = 0; i < linelen; i++)
    {
      if (!is_valid_char(line[i], m->empty, m->obstacle))
      {
        free(line);
        free_map_partial(m, row);
        return NULL;
      }
      m->grid[row][i] = line[i];
    }
    m->grid[row][linelen] = '\0';
    row++;
  }
  free(line);

  // validate row count
  if (row != m->rows)
  {
    free_map_partial(m, row);
    return NULL;
  }

  return m;
}

int min3(int a, int b, int c)
{
  int min = a;

  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}

t_square find_biggest_square(t_map *m)
{
  t_square best = {0, 0, 0};

  if (!m || !m->grid)
    return best;

  // allocate dp table
  int **dp = malloc(sizeof(int *) * m->rows);
  for (int i = 0; i < m->rows; i++)
    dp[i] = calloc(m->cols, sizeof(int));

  // fill dp table
  for (int i = 0; i < m->rows; i++)
  {
    for (int j = 0; j < m->cols; j++)
    {
      if (m->grid[i][j] == m->obstacle)
        dp[i][j] = 0;
      else
      {
        if (i == 0 || j == 0)
          dp[i][j] = 1;
        else
        {
          // left, top, top-left diagonal
          dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }

        // update best square (prefer top-left, dp stores bottom-right)
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

  // free dp table
  for (int i = 0; i < m->rows; i++)
    free(dp[i]);
  free(dp);

  return best;
}

void fill_and_print(t_map *m, t_square sq)
{
  // fill square
  for (int i = sq.row; i < sq.row + sq.size; i++)
  {
    for (int j = sq.col; j < sq.col + sq.size; j++)
    {
      m->grid[i][j] = m->full;
    }
  }

  // print map
  for (int i = 0; i < m->rows; i++)
    fprintf(stdout, "%s\n", m->grid[i]);
}

void process_file(FILE *f)
{
  t_map *m = read_map(f);

  if (!m)
  {
    ft_printerror();
    return;
  }

  // t_square sq = {0, 0, 0};
  t_square sq = find_biggest_square(m);
  fill_and_print(m, sq);
  free_map(m);
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
    FILE *f = fopen(argv[i], "r");
    if (!f)
    {
      ft_printerror();
      continue;
    }

    process_file(f);
    fclose(f);

    if (i < argc - 1)
      fprintf(stdout, "\n");
  }

  return 0;
}

// ./a.out example_file.txt
// cat example_file.txt | ./a.out