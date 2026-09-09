#include "solve_math_problems.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char *str_remove_spaces(char *line) {
  size_t w = 0;
  for (size_t i = 0; i < strlen(line); i++) {
    if (!isspace((unsigned char)line[i])) {
      line[w] = line[i];
      w++;
    }
  }
  line[w] = '\0';
  return line;
}

void create_grid_from_file(FILE *file, unsigned int **out, char *operators) {
  char *line = NULL;
  size_t linecapp = 0;

  while (getline(&line, &linecapp, file) != -1) {
    if (line[0] == '*' || line[0] == '+') {
      operators = str_remove_spaces(line);
    }
  }
}

uint64_t solve_problems_from_file(FILE *file) {
  uint64_t sum = 0;

  unsigned int **math_grid = NULL;
  char *operator = NULL;

  create_grid_from_file(file, math_grid, operator);

  return sum;
}
