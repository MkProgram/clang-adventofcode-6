#include "solve_math_problems.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  puts("Lets calculate math problems!");
  const char *floc = "math_problems.txt";
  FILE *file = NULL;

  file = fopen(floc, "r");
  if (file == NULL) {
    fprintf(stderr, "Can't open file \"%s\"", floc);
    return EXIT_FAILURE;
  }

  uint64_t answer = solve_problems_from_file(file);
  fclose(file);

  printf("The sum of the problems is: %" PRIu64 "\n", answer);

  return EXIT_SUCCESS;
}
