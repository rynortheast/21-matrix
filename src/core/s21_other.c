#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = s21_is_bad_matrix(A);

  if (status == 0 && (status = A->rows != A->columns ? 2 : 0) == 0) {
    if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (A->columns == 2) {
      *result = A->matrix[0][0] * A->matrix[1][1];
      *result -= A->matrix[0][1] * A->matrix[1][0];
    } else {
      for (int y = 0; status == 0 && y < A->columns; y += 1) {
        double aux = 0;
        matrix_t aux_matrix = {0};
        if ((status = s21_minor(A, 0, y, &aux_matrix)) == 0) {
          if ((status = s21_determinant(&aux_matrix, &aux)) == 0) {
            y % 2 ? (*result -= A->matrix[0][y] * aux)
                  : (*result += A->matrix[0][y] * aux);
            s21_remove_matrix(&aux_matrix);
          }
        }
      }
    }
  }

  return status;
}

int s21_minor(matrix_t *A, int row, int col, matrix_t *result) {
  int status = s21_is_bad_matrix(A);

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

int calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (s21_create_matrix(A->rows, A->columns, result) == 0) {
    matrix_t tmp;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        find_minor(i, j, A, &tmp);
        double det = 0.0;
        s21_determinant(&tmp, &det);
        result->matrix[i][j] = pow(-1, i + j) * det;
        s21_remove_matrix(&tmp);
      }
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = s21_is_bad_matrix(A);

  if (status == 0 && (status = A->rows != A->columns ? 2 : 0) == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      matrix_t aux_matrix = {0};
      if ((status = s21_create_matrix(A->rows, A->columns, &aux_matrix)) == 0) {
        for (int x = 0; status == 0 && x < A->rows; x += 1) {
          for (int y = 0; status == 0 && y < A->columns; y += 1) {
            double aux = 0.0;
            if ((status = s21_minor(A, x, y, &aux_matrix)) == 0) {
              if ((status = s21_determinant(&aux_matrix, &aux)) == 0)
                result->matrix[x][y] = pow(-1, x + y) * aux;
            }
          }
        }
        s21_remove_matrix(&aux_matrix);
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
