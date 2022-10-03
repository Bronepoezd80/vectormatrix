/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-10-03
 */
#ifndef VECTORMATRIX_ARRAY_H__
#define VECTORMATRIX_ARRAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <xalloc.h>

#define make_vector(V_, N_) ((V_) = xmalloc((N_) * sizeof *(V_)))
#define free_vector(V_) \
  do {                  \
    free(V_);           \
    V_ = NULL;          \
  } while (0)
#define print_vector(FMT_, V_, N_)                                        \
  do {                                                                    \
    for (size_t print_vector_loop_counter = 0;                            \
         print_vector_loop_counter < (N_); ++print_vector_loop_counter) { \
      printf(FMT_, (V_)[print_vector_loop_counter]);                      \
    }                                                                     \
    putchar('\n');                                                        \
  } while (0)

#define make_matrix(A_, M_, N_)                                                \
  do {                                                                         \
    make_vector(A_, (M_) + 1);                                                 \
    for (size_t make_matrix_loop_counter = 0; make_matrix_loop_counter < (M_); \
         ++make_matrix_loop_counter) {                                         \
      make_vector((A_)[make_matrix_loop_counter], (N_));                       \
    }                                                                          \
    (A_)[M_] = NULL;                                                           \
  } while (0)
#define free_matrix(A_)                              \
  do {                                               \
    if (A_ != NULL) {                                \
      for (size_t free_matrix_loop_counter = 0;      \
           (A_)[free_matrix_loop_counter] != NULL;   \
           ++free_matrix_loop_counter) {             \
        free_vector((A_)[free_matrix_loop_counter]); \
      }                                              \
      free_vector(A_);                               \
    }                                                \
  } while (0)
#define print_matrix(FMT_, A_, M_, N_)                                         \
  do {                                                                         \
    for (size_t print_matrix_loop_counter = 0; print_matrix_loop_counter < M_; \
         ++print_matrix_loop_counter) {                                        \
      print_vector(FMT_, A_[print_matrix_loop_counter], N_);                   \
    }                                                                          \
    putchar('\n');                                                             \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* VECTORMATRIX_ARRAY_H__ */