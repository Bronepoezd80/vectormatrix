/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

int main(void) {
  int vector_size = 100;
  double *x;
  make_vector(x, vector_size);
  for (int i = 0; i < vector_size; ++i) {
    x[i] = i * i * vector_size;
  }
  print_vector("%12.2f", x, vector_size);
  free_vector(x);

  return EXIT_SUCCESS;
}