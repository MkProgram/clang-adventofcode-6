#include "number_vec.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool vec_push(NumberVec *vec, uint64_t value) {

  if (vec->size == vec->capacity) {
    size_t capacity = vec->capacity == 0 ? 4 : vec->capacity * 2;
    uint64_t *grow = realloc(vec->data, capacity * sizeof vec->data[0]);
    if (grow == NULL) {
      return false;
    }
    vec->capacity = capacity;
    vec->data = grow;
  }
  vec->data[vec->size] = value;
  vec->size++;
  return true;
}

void vec_free(NumberVec *vec) {
  free(vec->data);

  vec->data = NULL;
  vec->size = 0;
  vec->capacity = 0;
}
