#include <stdio.h>

double x_k(double x, int k) {
    double a = 1;
    for (int i = 1; i <= k; i++) {
        a = a * ((x * x) / (2 * i * (2 * i - 1)));
    }
    return a;
}

int main() {
    double x;
    int k;
    scanf("%lf %d", &x, &k);
    printf("%lf\n", x_k(x, k));
}