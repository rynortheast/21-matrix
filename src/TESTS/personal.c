#include "../s21_matrix.h"

int main() {
  int res;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  res = s21_inverse_matrix(&A, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);

  printf("RESULT = %d\n", res);

  return 0;
}
