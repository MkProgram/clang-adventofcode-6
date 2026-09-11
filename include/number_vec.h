#ifndef NUMBER_VEC_H
#define NUMBER_VEC_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct {
  uint64_t *data;
  size_t size;
  size_t capacity;
} NumberVec;

bool vec_push(NumberVec *vec, uint64_t value);
void vec_free(NumberVec *vec);

#endif // #ifdef NUMBER_VEC_H
