#include "solve_math_problems.h"
#include "number_vec.h"
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

bool parse_numbers_into(const char *line, NumberVec *vec) {
  const char *cursor = line;
  while (*cursor != '\0') {
    char *next;
    errno = 0;
    uint64_t value = strtoull(cursor, &next, 10);

    if (errno == ERANGE) {
      fprintf(stderr, "Value too large, use a higher number type");
      return false;
    }

    if (next == cursor) {
      break;
    }

    cursor = next;

    if (!vec_push(vec, value)) {
      return false;
    }
  }
  return true;
}

void create_grid_from_file(FILE *file, uint64_t *out) {
  char *line = NULL;
  size_t linecapp = 0;
  size_t width = 0;
  size_t row_num = 0;
  char *operators;
  NumberVec v = {0};

  if (getline(&line, &linecapp, file) != -1) {
    parse_numbers_into(line, &v);
    width = v.size;
    row_num++;
  }

  while (getline(&line, &linecapp, file) != -1) {
    if (line[0] == '*' || line[0] == '+') {
      operators = str_remove_spaces(strdup(line));
      continue;
    }
    if (line[0] == '\n' || line[0] == '\r') {
      continue;
    }
    size_t before = v.size;
    parse_numbers_into(line, &v);
    size_t tokens_this_row = v.size - before;

    if (tokens_this_row != width) {
      fprintf(stderr, "Row %zu: expected %zu tokens, got %zu\n", row_num, width,
              tokens_this_row);
      break;
    }
    row_num++;
  }

  uint64_t sum = 0;

  for (size_t col = 0; col < width; ++col) {
    uint64_t rowSum = operators[col] == '*' ? 1 : 0;
    for (size_t row = 0; row < row_num; ++row) {
      uint64_t num = v.data[row * width + col];
      rowSum = operators[col] == '*' ? rowSum * num : rowSum + num;
    }
    sum += rowSum;
  }
  *out = sum;
  free(operators);
  if (line != NULL) {
    free(line);
  }
  vec_free(&v);
}

uint64_t solve_problems_from_file(FILE *file) {
  uint64_t sum = 0;

  create_grid_from_file(file, &sum);

  return sum;
}
