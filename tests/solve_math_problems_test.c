#include "number_vec.h"
#include "solve_math_problems.h"
#include <stdlib.h>

struct PARSE_NUMBERS_CASE {
  const char *name;
  const char *line;
  int expected[5];
};

size_t test_parse_numbers_into(void) {
  size_t failures = 0;
  struct PARSE_NUMBERS_CASE cases[] = {
      {"Simple", "1 2 3 4 5", {1, 2, 3, 4, 5}}};

  for (size_t i = 0; i < sizeof cases / sizeof cases[0]; ++i) {
    NumberVec v = {0};
  }

  return failures;
}

int main(void) {
  size_t failures = 0;

  if (failures == 0) {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
