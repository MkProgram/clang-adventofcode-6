#ifndef SOLVE_MATH_PROBLEMS_H
#define SOLVE_MATH_PROBLEMS_H
#include "number_vec.h"
#include <stdint.h>
#include <stdio.h>
char *str_remove_spaces(char *line);
bool parse_numbers_into(const char *line, NumberVec *vec);
uint64_t solve_problems_from_file(FILE *file);

#endif // ! SOLVE_MATH_PROBLEMS_H
