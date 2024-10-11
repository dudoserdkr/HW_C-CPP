#include <stdio.h>
#include <stdlib.h>

float calc_arithmetic_mean(float* ptr, int n) {
    float sum = 0;;
    for (int i = 0; i < n; i++) {
        sum += ptr[i];
    }
    return sum / n; // return type should be
}

float calc_dispersion(float*ptr, int n) {
    int avg_mean = calc_arithmetic_mean(ptr, n);
    int varience = 0;
    for (int i = 0; i < n; i++) {
        varience += (ptr[i] - avg_mean) * (ptr[i] - avg_mean);
    }
    return varience / n;
}

int main() {
    int n;

    for (int i = 0; i < 2; i++) {
        scanf("%d", &n);
        float *ptr = (float*)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            scanf("%f", &ptr[j]);
        }
        printf("\n");
        printf("%f\n", calc_arithmetic_mean(ptr, n));
        printf("%f\n", calc_dispersion(ptr, n));
        free(ptr);
    }
}