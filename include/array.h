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

/**
 * 1-Dimensional Array.
 *
 * n: column
 */
#define make_vector(V_, N_COL_) ((V_) = xmalloc((N_COL_) * sizeof *(V_)))

#define free_vector(V_) \
  do {                  \
    free(V_);           \
    V_ = NULL;          \
  } while (0)

#define print_vector(FMT_, V_, N_COL_)                                        \
  do {                                                                        \
    for (size_t print_vector_loop_counter = 0;                                \
         print_vector_loop_counter < (N_COL_); ++print_vector_loop_counter) { \
      printf(" .col[%zu] ", print_vector_loop_counter + 1);                   \
      printf(FMT_, (V_)[print_vector_loop_counter]);                          \
    }                                                                         \
    putchar('\n');                                                            \
  } while (0)

/**
 * 2-Dimensional Array.
 *
 * m: row, n: column
 */
#define make_matrix(A_, M_ROW_, N_COL_)                                     \
  do {                                                                      \
    make_vector(A_, (M_ROW_) + 1);                                          \
    for (size_t make_matrix_loop_counter = 0;                               \
         make_matrix_loop_counter < (M_ROW_); ++make_matrix_loop_counter) { \
      make_vector((A_)[make_matrix_loop_counter], (N_COL_));                \
    }                                                                       \
    (A_)[M_ROW_] = NULL;                                                    \
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

#define print_matrix(FMT_, A_, M_ROW_, N_COL_)                              \
  do {                                                                      \
    for (size_t print_matrix_loop_counter = 0;                              \
         print_matrix_loop_counter < M_ROW_; ++print_matrix_loop_counter) { \
      printf("        row[%zu]->", print_matrix_loop_counter + 1);          \
      print_vector(FMT_, (A_)[print_matrix_loop_counter], (N_COL_));        \
    }                                                                       \
  } while (0)

/**
 * 3-Dimensional Array.
 *
 * m: row, n: column, o: level
 */
#define make_3array(A_, M_ROW_, N_COL_, O_LVL_)                             \
  do {                                                                      \
    make_vector(A_, (O_LVL_) + 1);                                          \
    for (size_t make_3array_loop_counter = 0;                               \
         make_3array_loop_counter < (O_LVL_); ++make_3array_loop_counter) { \
      make_matrix((A_)[make_3array_loop_counter], (M_ROW_), (N_COL_));      \
    }                                                                       \
    (A_)[O_LVL_] = NULL;                                                    \
  } while (0)

#define free_3array(A_)                              \
  do {                                               \
    if (A_ != NULL) {                                \
      for (size_t free_3array_loop_counter = 0;      \
           (A_)[free_3array_loop_counter] != NULL;   \
           ++free_3array_loop_counter) {             \
        free_matrix((A_)[free_3array_loop_counter]); \
      }                                              \
      free_vector(A_);                               \
    }                                                \
  } while (0)

#define print_3array(FMT_, A_, M_ROW_, N_COL_, O_LVL_)                         \
  do {                                                                         \
    for (size_t print_3array_loop_counter = 0;                                 \
         print_3array_loop_counter < O_LVL_; ++print_3array_loop_counter) {    \
      printf("    lvl[%zu]\n", print_3array_loop_counter + 1);                 \
      print_matrix(FMT_, (A_)[print_3array_loop_counter], (M_ROW_), (N_COL_)); \
    }                                                                          \
  } while (0)

/**
 * 4-Dimensional Array.
 *
 * m: row, n: column, o: level, p: block
 */
#define make_4array(A_, M_ROW_, N_COL_, O_LVL_, P_BLK_)                     \
  do {                                                                      \
    make_vector(A_, (P_BLK_) + 1);                                          \
    for (size_t make_4array_loop_counter = 0;                               \
         make_4array_loop_counter < (P_BLK_); ++make_4array_loop_counter) { \
      make_3array((A_)[make_4array_loop_counter], (M_ROW_), (N_COL_),       \
                  (O_LVL_));                                                \
    }                                                                       \
    (A_)[P_BLK_] = NULL;                                                    \
  } while (0)

#define free_4array(A_)                              \
  do {                                               \
    if (A_ != NULL) {                                \
      for (size_t free_4array_loop_counter = 0;      \
           (A_)[free_4array_loop_counter] != NULL;   \
           ++free_4array_loop_counter) {             \
        free_3array((A_)[free_4array_loop_counter]); \
      }                                              \
      free_vector(A_);                               \
    }                                                \
  } while (0)

#define print_4array(FMT_, A_, M_ROW_, N_COL_, O_LVL_, P_BLK_)                \
  do {                                                                        \
    for (size_t print_4array_loop_counter = 0;                                \
         print_4array_loop_counter < P_BLK_; ++print_4array_loop_counter) {   \
      printf("blk[%zu]\n", print_4array_loop_counter + 1);                    \
      print_3array(FMT_, (A_)[print_4array_loop_counter], (M_ROW_), (N_COL_), \
                   (O_LVL_));                                                 \
    }                                                                         \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* VECTORMATRIX_ARRAY_H__ */