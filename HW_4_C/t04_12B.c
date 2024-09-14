#include <stdio.h>

double y(double x, int n) {
    double a = (double)1;
    double sum = a;

    for (int i = 1; i <= n; i ++) {
        a *= x * x * x;
        sum += a;
    }
    return sum;

}

int main() {
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%lf\n", y(x, n));
}