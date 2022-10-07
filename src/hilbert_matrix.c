/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-04
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

double **hilbert_matrix(int);

int main(void) {
  double **H;
  int n = 8;

  H = hilbert_matrix(n);
  print_matrix("%8.3f", H, n, n);
  free_matrix(H);

  return EXIT_SUCCESS;
}

double **hilbert_matrix(int n) {
  double **H;
  make_matrix(H, n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      H[i][j] = 1.0 / (1 + i + j);
    }
  }
  return H;
}
