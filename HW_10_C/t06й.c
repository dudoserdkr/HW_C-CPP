#include <stdio.h>
#include <stdlib.h>

float** create_matrixf(int rows, int cols) {
    float **matrix = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float*)malloc(cols * sizeof(float));
    }
    return matrix;
}

void input_matrixf(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("Input %d row: ", i+1);
        for(int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}


void print_matrixf(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}


typedef struct Matrix {
    int rows;
    int cols;
    float **data;
} Matrix;

int main() {
    int rows, cols;
    printf("Input rows and cols: ");
    scanf("%d %d", &rows, &cols);
    Matrix m = {rows, cols, create_matrixf(rows, cols)};
    input_matrixf(m.data, m.rows, m.cols);
    print_matrixf(m.data, m.rows, m.cols);
}