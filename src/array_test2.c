/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

int main(void) {
  int m = 5, n = 8;
  double **a;
  make_matrix(a, m, n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = i * j * m;
    }
  }
  print_matrix("%12.2f", a, m, n);
  free_matrix(a);

  return EXIT_SUCCESS;
}