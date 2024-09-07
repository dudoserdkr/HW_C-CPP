#include <stdio.h>
#include <math.h>

float invsqrt(float x, float a) {
    return x / sqrtf(1 + a * x * x);
}

float derivative_invsqrt(float x, float a) {
    return powf(invsqrt(x, a), 3) / powf(x, 3);
}

int main() {
    float x, a;
    printf("Write a float numbers x, a: ");
    scanf("%f %f", &x, &a);

    printf("invsqrt(%f, %f) = %f\n", x, a, invsqrt(x, a));
    printf("derivative_invsqrt(%f, %f) = %f\n", x, a, derivative_invsqrt(x, a));
}