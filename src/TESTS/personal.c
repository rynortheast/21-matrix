#include "../s21_matrix.h"

int main() {
  matrix_t A = {0};
  double result = 0;

  for (int q = 0; q < 10; q += 1) {
    s21_create_matrix(q, q, &A);

    for (int x = 0; x < q; x += 1)
      for (int y = 0; x < q; x += 1) A.matrix[x][y] = 5;

    int u = s21_determinant(&A, &result);

    printf("TEST - %d - %d\n", q, u);

    s21_remove_matrix(&A);
  }

  return 0;
}
