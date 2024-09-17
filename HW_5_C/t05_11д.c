#include <stdio.h>

double calc_rec(int n) {
    double a[n];
    double b = 2;
    a[0] = 1;
    a[1] = 1;
    a[2] = 1;
    double S = a[0] / b;

    for (int i = 2; i <= n; i++) {
        if (i > 3) {
            a[i - 1] = a[i - 2] + a[i - 4];
        }
        b *= 2;
        S += a[i - 1] / b;
    }
    return S;

}

int main() {

    int n;
    scanf("%d", &n);
    printf("%lf\n", calc_rec(n));
}