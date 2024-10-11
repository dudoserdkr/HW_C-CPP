#include <stdio.h>
#include <stdlib.h>

int** input_matrix(int n, int m) {
    int** ptr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        ptr[i] = (int*)malloc(m * sizeof(int));
        printf("Input row %d: ", i + 1);
        for (int j = 0; j < m; j++)
        scanf("%d", &ptr[i][j]);
    }
    return ptr;
}

void delete_matrix(int **ptr, int n) {
    for (int i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);
}


void print_matrix(int** ptr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}


int** minor(int**matrix, int n, int p) {
    int** minor = (int**)calloc(n-1, sizeof(int*));

    for (int i = 0; i < n-1; i++) {
        minor[i] = (int*)calloc(n-1, sizeof(int));
    }

    int mi = 0, mj = 0; // minor indexes

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == p) {
                continue;
            }
            minor[mi][mj] = matrix[i][j];
            mj++;
        }
        mj = 0;
        mi++;
    }
    return minor;
}

int determinant(int**matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    int sign = 1;
    int det = 0;

    for (int i = 0; i < n; i++) {
        det += sign * matrix[0][i] * determinant(minor(matrix, n, i), n - 1);
        sign = -sign;
    }
    return det;
}

int main() {
    printf("Intput n, m: ");

    int n, m;
    scanf("%d %d", &n, &m);

    int** ptr = input_matrix(n, m);

    if (ptr){
        print_matrix(ptr, n, m);
        printf("Determinant: %d\n", determinant(ptr, n));
        delete_matrix(ptr, n);
    }

}