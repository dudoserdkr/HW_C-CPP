#include <stdio.h>

double cosh(double epsilon, double x) {
    double a = 1;
    double S = 1;
    int k = 1;

    while (a > epsilon) {
        a = a * ((x * x) / (k * (k + 1)));
        k += 2;
        S += a;
    }

    return S;
}

int main() {
    double epsilon, x;
    scanf("%lf %lf", &epsilon, &x);
    printf("%lf\n", cosh(epsilon, x));
}