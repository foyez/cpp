#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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

// Core functions
t_map *read_map(FILE *fp);
void free_map(t_map *map);
t_square find_biggest_square(t_map *map);
void fill_and_print(t_map *map, t_square sq);

#endif