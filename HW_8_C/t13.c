#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void input_matrix(int matrix[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("Input row %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
}

void product(int A[][MAX], int B[][MAX], int C[][MAX], int n, int m, int p) {
    // Initialize C to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }

    // A is n x m, B is m x p, C is n x p
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(int matrix[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, m, p;
    printf("Input n, m, p: ");
    scanf("%d %d %d", &n, &m, &p);

    input_matrix(A, n, m);
    input_matrix(B, m, p);

    product(A, B, C, n, m, p);

    printf("Resulting matrix C:\n");
    print(C, n, p);

    return 0;
}