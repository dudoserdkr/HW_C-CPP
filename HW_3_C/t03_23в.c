#include <stdio.h>

long double leakyRelu(long double a, long double x) {
    if (x > 0) {
        return a * x;
    }
    return 0;
}

long double derivatibe_leakyRelu(long double a, long double x) {
    if (x > 0) {
        return a;
    }
    return 0;
}

int main() {
    long double a, x;
    scanf("%Lf %Lf", &a, &x);
    printf("%Lf\n", leakyRelu(a, x));
    printf("%Lf\n", derivatibe_leakyRelu(a, x));
}