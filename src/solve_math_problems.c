#include "solve_math_problems.h"
#include <_stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void create_grid_from_file(FILE *file, unsigned int **out, char *operators) {
  char *line = NULL;
  size_t linecapp = 0;

  while (getline(&line, &linecapp, file) != -1) {
  }
}

uint64_t solve_problems_from_file(FILE *file) {
  uint64_t sum = 0;

  unsigned int **math_grid = NULL;
  char *operator = NULL;

  create_grid_from_file(file, math_grid, operator);

  return sum;
}
