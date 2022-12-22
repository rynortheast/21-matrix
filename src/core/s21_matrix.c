#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = INCORRECT_MATRIX;

  if (rows > 0 && columns > 0) {
    if (result->matrix = (double **)calloc(rows, sizeof(double *))) {
      result->columns = columns;
      result->rows = rows;

      for (int x = 0; x < rows; x += 1) {
        if (!(result->matrix[x] = (double *)calloc(columns, sizeof(double)))) {
          for (int q = 0; q < x; q += 1) free(result->matrix[q]);
          free(result->matrix);
          status = ALLOC_FAIL;
        }
      }

      if (status == INCORRECT_MATRIX) {
        for (int x = 0; x < rows; x += 1) {
          for (int y = 0; y < columns; y += 1) {
            result->matrix[x][y] = 0;
          }
        }
        status = OK;
      }
    } else {
      status = ALLOC_FAIL;
    }
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int x = 0; x < A->rows; x += 1) {
      free(A->matrix[x]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
  }
}
