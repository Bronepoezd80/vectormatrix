/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

typedef struct matrix_ {
  double **a;
  int n_col;
  int m_row;
} matrix;

int main(void) {
  matrix a = {NULL, 5, 8};
  make_matrix(a.a, a.m_row, a.n_col);
  for (int i = 0; i < a.m_row; ++i) {
    for (int j = 0; j < a.n_col; ++j) {
      a.a[i][j] = j + ((double)i / 10);
    }
  }
  print_matrix("%.2f", a.a, a.m_row, a.n_col);
  free_matrix(a.a);

  return EXIT_SUCCESS;
}