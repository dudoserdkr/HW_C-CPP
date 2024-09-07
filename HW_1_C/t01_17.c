#include <stdio.h>
#include <math.h>

int main() {
    double num;
    printf("Enter a real number between 0 and 1000: ");
    scanf("%lf", &num);

    if (num < 0 || num > 1000) {
        printf("Number out of range.\n");
        return 1;
    }

    double result = pow(num, 8);
    printf("%.20f\n", result);
    return 0;
}