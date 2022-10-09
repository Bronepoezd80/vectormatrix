/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-06
 */

#include <stdio.h>
#include <stdlib.h>

#include <array.h>

int main(void) {
  int m = 2, n = 3, o = 4, p = 5;
  double ****a;
  make_4array(a, m, n, o, p);
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < o; ++j) {
      for (int k = 0; k < m; ++k) {
        for (int l = 0; l < n; ++l) {
          a[i][j][k][l] = i * j * k * l;
        }
      }
    }
  }
  print_4array("%8.2f", a, m, n, o, p);
  free_4array(a);

  return EXIT_SUCCESS;
}