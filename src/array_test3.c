/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-07
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

int main(void) {
  int m = 5, n = 6, o = 7;
  double ***a;
  make_3array(a, m, n, o);
  for (int i = 0; i < o; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        a[i][j][k] = i + j + k;
      }
    }
  }
  print_3array("%8.2f", a, m, n, o);
  free_3array(a);

  return EXIT_SUCCESS;
}