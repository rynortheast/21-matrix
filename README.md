
# 21-matrix

<div align="center">PREVIEW_WILL_BE_ADDED_LATER.png</div>

***

Educational project s21_matrix from organization «School 21».  
  
Implementation of some functions for processing numerical matrices in C programming languages. Develop basic operations with matrices: creation, deletion, addition and subtraction of two matrices, multiplication of a matrix by a number and another matrix, transposition, inversion, search for a determinant.

<details>
<summary>[ SPOILER ] Overview of implemented code</summary>

| No. | Function | Description | Status |
| ------ | ------ | ------ | ------ |
| 1 | int s21_create_matrix(int rows, int columns, matrix_t *result) | creating matrices | ✅ |
| 2 | void s21_remove_matrix(matrix_t *A) | cleaning of matrices | ✅ |
| 3 | int s21_eq_matrix(matrix_t *A, matrix_t *B) | matrix comparison | ✅ |
| 4 | int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | adding matrices | ✅ |
| 5 | int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | subtracting matrices | ✅ |
| 6 | int s21_mult_number(matrix_t *A, double number, matrix_t *result) | matrix multiplication by scalar | ✅ |
| 7 | int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | multiplication of two matrices | ✅ |
| 8 | int s21_transpose(matrix_t *A, matrix_t *result) | matrix transpose | ✅ |
| 9 | int s21_calc_complements(matrix_t *A, matrix_t *result) | minor of matrix and matrix of algebraic complements | ✅ |
| 10 | int s21_determinant(matrix_t *A, double *result) | matrix determinant | ✅ |
| 11 | int s21_inverse_matrix(matrix_t *A, matrix_t *result) | inverse of matrix | ✅ |

</details>

— Thanks to 21-SCHOOL for provided assignment and special learning conditions ✌️🔥

## Usage

1. Clone this repository via
    - SSH `git@github.com:rynortheast/21-matrix.git` or
    - HTTPS `https://github.com/rynortheast/21-matrix.git`
2. Change code base if necessary
3. Run `make test` to build project and run main tests
4. Run `make personal` to build project and run personal test
5. Run `make s21_matrix.a` to build a static lib
