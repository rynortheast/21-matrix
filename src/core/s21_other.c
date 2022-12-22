#include "../s21_matrix.h"

void calcMinor(double **A, double **aux, int skipRow, int skipCol, int size) {
  for (int row = 0, x = 0; row < size; row += 1) {
    for (int col = 0, y = 0; col < size; col += 1) {
      if (row != skipRow && col != skipCol) {
        aux[x][y++] = A[row][col];
        if (y == size - 1) {
          y = 0;
          x++;
        }
      }
    }
  }
}

double calcDeterminant(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t aux = {0};
  double result = 0;

  s21_create_matrix(size, size, &aux);
  for (int sign = 1, x = 0; x < size; x += 1, sign *= (-1)) {
    calcMinor(A, 0, x, &aux);
    result += sign * A->matrix[0][x] * calcDeterminant(&aux, size - 1);
  }

  s21_remove_matrix(&aux);
  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_bad_matrix(A) == FAILURE) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    calcDeterminant(A, A->rows);

  return OK;
}

int s21_minor(matrix_t *A, int row, int col, matrix_t *result) {
  int status = s21_is_bad_matrix(A);
  s21_remove_matrix(result);

  if ((status = A->rows > 1 && A->columns > 1 ? 0 : 2) == 0) {
    if (!(status = s21_create_matrix(A->rows - 1, A->columns - 1, result))) {
      for (int x = 0; x < result->rows; x += 1) {
        for (int y = 0; y < result->columns; y += 1) {
          result->matrix[x][y] =
              A->matrix[x + (x >= row ? 1 : 0)][y + (y >= col ? 1 : 0)];
        }
      }
    }
  }

  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = s21_is_bad_matrix(A);
  s21_remove_matrix(result);

  if (status == 0 && (status = A->rows != A->columns ? 2 : 0) == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      matrix_t aux_matrix = {0};
      for (int x = 0; status == 0 && x < A->rows; x += 1) {
        for (int y = 0; status == 0 && y < A->columns; y += 1) {
          double aux = 0.0;
          if ((status = s21_minor(A, x, y, &aux_matrix)) == 0) {
            if ((status = s21_determinant(&aux_matrix, &aux)) == 0)
              result->matrix[x][y] = pow(-1, x + y) * aux;
            s21_remove_matrix(&aux_matrix);
          }
        }
      }
    }
  }

  return status;
}

int s21_is_bad_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;

  if (s21_is_bad_matrix(A) == 0) {
    if (s21_is_bad_matrix(B) == 0)
      status = (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
  }

  return status;
}

int s21_is_bad_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}
