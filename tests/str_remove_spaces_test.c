#include "solve_math_problems.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct REMOVE_CASE {
  const char *name;
  char str[32];
  const char *expected;
};

size_t test_str_remove_spaces(void) {
  size_t failures = 0;
  struct REMOVE_CASE cases[] = {{"Simple", "1 2\n", "12"},
                                {"Longer", "1 2 345 4 3 5 67", "1234543567"}};

  for (size_t i = 0; i < sizeof cases / sizeof cases[0]; ++i) {
    char *actual = str_remove_spaces(cases[i].str);

    if (strcmp(actual, cases[i].expected) != 0) {
      fprintf(stderr, "FAILURE: %s: Expected %s, found %s\n", cases[i].name,
              cases[i].expected, actual);
      ++failures;
    }
  }

  return failures;
}

int main(void) {
  size_t failures = 0;

  failures = test_str_remove_spaces();
  if (failures == 0) {
    puts("All tests pass!");
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
