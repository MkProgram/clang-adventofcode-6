#include "solve_math_problems.h"
#include "number_vec.h"
#include <_string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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

bool parse_number_into(const char *line, NumberVec *vec) {
  const char *cursor = line;
  while (*cursor != '\0') {
    char *next;
    errno = 0;
    uint64_t value = strtoull(cursor, &next, 10);

    if (errno == ERANGE) {
      fprintf(stderr, "Value too large, use a higher number type");
      return false;
    }

    cursor = next;

    if (!vec_push(vec, value)) {
      return false;
    }
  }
  return true;
}

void create_grid_from_file(FILE *file, unsigned int ***out, char **operators) {
  char *line = NULL;
  size_t linecapp = 0;
  NumberVec v = {0};
  size_t width = 0;
  size_t row_num = 0;

  if (getline(&line, &linecapp, file) != -1) {
    parse_number_into(line, &v);
    width = v.size;
    row_num++;
  }

  while (getline(&line, &linecapp, file) != -1) {
    if (line[0] == '*' || line[0] == '+') {
      *operators = str_remove_spaces(strdup(line));
      continue;
    }
    if (line[0] == '\n' || line[0] == '\r') {
      continue;
    }
    size_t before = v.size;
    parse_number_into(line, &v);
    size_t tokens_this_row = v.size - before;

    if (tokens_this_row != width) {
      fprintf(stderr, "Row %zu: expected %zu tokens, go %zu\n", row_num, width,
              tokens_this_row);
      break;
    }
    row_num++;
  }

  if (line != NULL) {
    free(line);
  }
}

uint64_t solve_problems_from_file(FILE *file) {
  uint64_t sum = 0;

  unsigned int **math_grid = NULL;
  char *operator = NULL;

  create_grid_from_file(file, &math_grid, &operator);

  free(operator);
  free(math_grid);
  return sum;
}
