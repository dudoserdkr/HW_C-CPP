#include <stdio.h>
#include <stdlib.h>

void print_arr(int** ptr, int* N,int M) {
    for (int i = 0; i < *N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

int** delete_odd_rows(int** ptr, int* N, int m) {
    int odd_rows = (*N + 1) / 2;

    int** new_arr = (int**)malloc(odd_rows * sizeof(int*));

    for (int i = 0,j = 0; i < *N; i+=2, j++) {
        new_arr[j] = ptr[i];
    }
    *N = odd_rows;
    return new_arr;
}

int random_number() {
    return rand() % 1000;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int** ptr = (int**)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        ptr[i] = (int*)malloc(M * sizeof(int));

        for (int j = 0; j < M; j++) {
            ptr[i][j] = random_number();
        }
    }

    print_arr(ptr, &N, M);

    ptr = delete_odd_rows(ptr, &N, M);
    printf("-----------------------\n");
    print_arr(ptr, &N, M);

}