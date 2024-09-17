#include <stdio.h>

double calc_rec(int n) {
    double a[n - 1];
    double b[n - 1];
    int c = 3;
    a[0] = 2;
    a[1] = 1;
    b[0] = 1;
    b[1] = 0;
    double S = 0;

    for (int k = 1; k <= n; k++) {
        c *= 9;
        if (k > 2) {
            b[k - 1] = 2 * b[k - 2] + a[k - 2];
            a[k - 1] = a[k - 2] / (k + 1) + a[k - 3] + b[k - 1];
        }

        S += (double) c / (a[k - 1] * b[k - 1] + 1);
        printf("%lf\n", S);
    }
    return S;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", calc_rec(n));
}