#include "number_vec.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  NumberVec v = {0};
  for (uint64_t i = 0; i < 10000; ++i) {
    if (!vec_push(&v, i)) {
      fprintf(stderr, "Cannot push item %" PRIu64 "\n", i);
      return EXIT_FAILURE;
    }
  }
  if (v.size != 10000) {
    fprintf(stderr,
            "Size of the vector is not correct. Expected 10000, found %zu\n",
            v.size);
    return EXIT_FAILURE;
  }
  if (v.data[9999] != 9999) {
    fprintf(stderr,
            "Last element is not correct. Expected 9999, found %" PRIu64 "\n",
            v.data[9999]);
    return EXIT_FAILURE;
  }

  vec_free(&v);

  puts("All vector tests pass!");

  return EXIT_SUCCESS;
}
