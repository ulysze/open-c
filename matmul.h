#include <math.h>
#include <stdio.h>

#define N 10

typedef struct {
        size_t columns;
        size_t rows;

        double m[N][N];

} Matrix;

Matrix read_matrix(void);
Matrix mul(const Matrix*, const Matrix*);
void display_matrix(const Matrix*);