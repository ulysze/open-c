#include "matmul.h"

int main(void) {

        Matrix m1 = read_matrix();
        Matrix m2 = read_matrix();
        Matrix m3 = mul(&m1, &m2);

        display_matrix(&m3);
}

Matrix read_matrix(void) {
        printf("Entrez les dimensions pour la matrice (ligne et colonnes): \n");
        size_t rows, columns;
        Matrix result;
        if (scanf("%lu %lu", &rows, &columns) != 2) {
                printf("Entrée invalide\n");
                return (Matrix){0, 0};
        } else if (rows  >= N || columns >= N) {
                printf("Dimension must be smaller than %d\n", N);
                return (Matrix){0, 0};
        } else {
                result.columns = columns;
                result.rows = rows;
                for (size_t i = 0; i < rows; ++i) {
                        for (size_t j = 0; j < columns; ++j) {
                                printf("M[%lu, %lu] = ", i + 1, j + 1);
                                scanf("%lf", &result.m[i][j]);
                        }
                }
                return result;
        }
}

Matrix mul(const Matrix* aptr, const Matrix* bptr) {
        if (aptr->columns != bptr->rows) {
                return *aptr;
        } else {
                Matrix result;
                for (size_t i = 0; i < aptr -> rows; ++i) {
                        for (size_t j = 0; j < bptr -> columns; j++) {
                                for (size_t k = 0; k < aptr -> columns; ++k) {
                                        result.m[i][j] += aptr -> m[i][k] * bptr -> m[k][j];
                                }
                        }
                
                }
                return result;
        }
}

void display_matrix(const Matrix* mptr) {
        for (size_t i = 0; i < mptr -> rows; i++) {
                printf("M[%lu] = ", i + 1);
                for (size_t j = 0; i < mptr -> columns; j++) {
                        printf("%lf ", mptr -> m[i][j]);
                }
                printf("\n");
        }       
}