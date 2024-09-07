#include <stdio.h>
#include <math.h>

double calculate_median(double a, double b, double c) {
    return sqrt((2 * b * b + 2 * c * c - a * a) / 4.0);
}

int main() {
    double a, b, c;
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double median_a = calculate_median(a, b, c);
    double median_b = calculate_median(b, a, c);
    double median_c = calculate_median(c, a, b);

    printf("Median to side a: %.4f\n", median_a);
    printf("Median to side b: %.4f\n", median_b);
    printf("Median to side c: %.4f\n", median_c);
}