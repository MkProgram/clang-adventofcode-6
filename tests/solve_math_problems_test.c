#include "number_vec.h"
#include "solve_math_problems.h"
#include <inttypes.h>
#include <stdlib.h>

struct PARSE_NUMBERS_CASE {
  const char *name;
  const char *line;
  u_int64_t expected[5];
};

size_t test_parse_numbers_into(void) {
  size_t failures = 0;
  struct PARSE_NUMBERS_CASE cases[] = {
      {"Simple", "1 2 3 4 5", {1, 2, 3, 4, 5}}};

  for (size_t i = 0; i < sizeof cases / sizeof cases[0]; ++i) {
    NumberVec v = {0};

    bool success = parse_numbers_into(cases[i].line, &v);

    if (!success) {
      fprintf(stderr,
              "Test case '%s' failed: parse_numbers_into returned false\n",
              cases[i].name);
      failures++;
      continue;
    }

    for (size_t j = 0; j < v.size; ++j) {
      if (v.data[j] != cases[i].expected[j]) {
        fprintf(stderr,
                "Test case '%s' failed: expected %" PRIu64 ", got %" PRIu64
                "\n",
                cases[i].name, cases[i].expected[j], v.data[j]);
        failures++;
      }
    }
  }

  return failures;
}

size_t test_example_file(void) {
  const int64_t expected = 4277556;
  size_t failures = 0;
  FILE *file = fopen("tests/example.txt", "r");
  if (!file) {
    fprintf(stderr, "Failed to open example.txt\n");
    return 1;
  }

  uint64_t result = solve_problems_from_file(file);
  fclose(file);

  if (result != expected) {
    fprintf(stderr,
            "Test case 'example.txt' failed: expected %" PRIu64 ", got %" PRIu64
            "\n",
            expected, result);
    failures++;
  }

  return failures;
}

int main(void) {
  size_t failures = 0;

  failures += test_parse_numbers_into();
  failures += test_example_file();

  if (failures == 0) {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
