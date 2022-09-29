#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 1;

  if (rows > 0 && columns > 0) {
    double **matrix =
        calloc(rows * columns * sizeof(double) + rows * sizeof(double *), 1);

    if (matrix != NULL) {
      double *cell = (double *)(matrix + rows);
      for (int index = 0; index < rows; index += 1)
        matrix[index] = cell + columns * index;
      result->columns = columns;
      result->matrix = matrix;
      result->rows = rows;
      status = 0;
    }
  }

  return status;
}

//  TODO [s21_remove_matrix] Проверить на работоспособность.
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) free(A->matrix);
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}
