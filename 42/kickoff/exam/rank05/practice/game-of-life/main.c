#include <stdlib.h>
#include <unistd.h>

typedef struct s_pen
{
  int x;
  int y;
  int pen_down;
} t_pen;

typedef struct s_board
{
  char **grid;
  int width;
  int height;
} t_board;

void ft_putchar(int c)
{
  write(1, &c, 1);
}

t_board *create_board(int width, int height)
{
  t_board *board = malloc(sizeof(t_board));
  board->width = width;
  board->height = height;
  board->grid = malloc(sizeof(char *) * height);

  for (int i = 0; i < height; i++)
  {
    board->grid[i] = calloc(width, sizeof(char));
  }

  return board;
}

void free_board(t_board *board)
{
  for (int i = 0; i < board->height; i++)
    free(board->grid[i]);
  free(board->grid);
  free(board);
}

void process_command(t_board *board, t_pen *pen, char cmd)
{
  int new_x = pen->x;
  int new_y = pen->y;

  if (cmd == 'w') // up
    new_y = pen->y - 1;
  else if (cmd == 's') // down
    new_y = pen->y + 1;
  else if (cmd == 'a') // left
    new_x = pen->x - 1;
  else if (cmd == 'd') // right
    new_x = pen->x + 1;
  else if (cmd == 'x')
  {
    pen->pen_down = !pen->pen_down;
    if (pen->pen_down)
      board->grid[pen->y][pen->x] = '0';
    return;
  }
  else
    return; // invalid command

  // check bounds
  if (new_x >= 0 && new_x < board->width && new_y >= 0 && new_y < board->height)
  {
    pen->x = new_x;
    pen->y = new_y;

    // draw if pen is down
    if (pen->pen_down)
      board->grid[pen->y][pen->x] = '0';
  }
}

int count_neighbors(t_board *board, int x, int y)
{
  int count = 0;

  // check all 8 neighbors
  for (int dy = -1; dy <= 1; dy++)
  {
    for (int dx = -1; dx <= 1; dx++)
    {
      if (dx == 0 && dy == 0)
        continue;

      int nx = x + dx;
      int ny = y + dy;

      // check bounds
      if (nx >= 0 && nx < board->width && ny >= 0 && ny < board->height)
      {
        if (board->grid[ny][nx] == '0')
          count++;
      }
    }
  }

  return count;
}

void simulate_generation(t_board *board)
{
  t_board *new_board = create_board(board->width, board->height);

  for (int y = 0; y < board->height; y++)
  {
    for (int x = 0; x < board->width; x++)
    {
      int neighbors = count_neighbors(board, x, y);
      int is_alive = (board->grid[y][x] == '0');

      // Game of Life rules:
      // 1. any live cell with 2 or 3 neighbors survives
      // 2. any dead cell with exactly 3 neighbors becomes alive
      // 3. all other cells die or stay dead

      if (is_alive && (neighbors == 2 || neighbors == 3))
        new_board->grid[y][x] = '0';
      else if (!is_alive && neighbors == 3)
        new_board->grid[y][x] = '0';
      else
        new_board->grid[y][x] = ' ';
    }
  }

  // copy new board to old board
  for (int y = 0; y < board->height; y++)
  {
    for (int x = 0; x < board->width; x++)
    {
      board->grid[y][x] = new_board->grid[y][x];
    }
  }

  free_board(new_board);
}

void print_board(t_board *board)
{
  for (int y = 0; y < board->height; y++)
  {
    for (int x = 0; x < board->width; x++)
    {
      if (board->grid[y][x] == '0')
        ft_putchar('0');
      else
        ft_putchar(' ');
    }
    ft_putchar('\n');
  }
}

int main(int argc, char **argv)
{
  if (argc != 4)
    return 1;

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  int iters = atoi(argv[3]);

  if (width <= 0 || height <= 0 || iters < 0)
    return 1;

  t_board *board = create_board(width, height);

  // top-left, pen up
  t_pen pen;
  pen.x = 0;
  pen.y = 0;
  pen.pen_down = 0;

  // read commands from stdin
  char cmd;
  while (read(0, &cmd, 1) > 0)
    process_command(board, &pen, cmd);

  // simulate game of life
  for (int i = 0; i < iters; i++)
    simulate_generation(board);

  print_board(board);

  free_board(board);

  return 0;
}

// echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
// echo 'sdxssdswdxdddxsaddawxwdxwaa' | ./a.out 10 6 0 | cat -e
