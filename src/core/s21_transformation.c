#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = s21_is_bad_matrix(A);

  if (status == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[y][x] = A->matrix[x][y];
        }
      }
    }
  }

  return status;
}

int inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int res = 0;
  s21_determinant(A, &det);
  if (A->rows != A->columns || fabs(det) < 1e-7) {
    res = 2;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      } else {
        matrix_t buf2, buf3;
        s21_transpose(A, &buf2);
        s21_calc_complements(&buf2, &buf3);
        nocr_mult(&buf3, 1.0 / det, result);
        s21_remove_matrix(&buf2);
        s21_remove_matrix(&buf3);
      }
    } else {
      res = 1;
    }
  }
  return res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = s21_is_bad_matrix(A);

  if (!status) {
    double aux = 0;
    if ((status = s21_determinant(A, &aux)) == 0) {
      if (!(status = A->rows != A->columns || fabs(aux) < 1e-7 ? 2 : 0)) {
        if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
          if (A->rows == 1) {
            result->matrix[0][0] = 1.0 / A->matrix[0][0];
          } else {
            matrix_t aux_matrix_1 = {0};
            matrix_t aux_matrix_2 = {0};
            s21_transpose(A, &aux_matrix_1);
            s21_calc_complements(&aux_matrix_1, &aux_matrix_2);
            s21_mult_number(&aux_matrix_2, 1.0 / aux, result);
            s21_remove_matrix(&aux_matrix_1);
            s21_remove_matrix(&aux_matrix_2);
          }
        }
      }
    }
  }

  return status;
}
