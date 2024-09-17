#include <stdio.h>

long double calc_pi(long double epsilon) {
    long double a = 1;
    long double S = a;
    int k = 2;

    while (a > epsilon) {
        a = 1 / (long double)(k * k * k * k);
        S += a;
        k++;
    }

    return S;
}

int main() {
    long double epsilon;
    scanf("%Lf", &epsilon);
    printf("%Lf\n", calc_pi(epsilon));
}