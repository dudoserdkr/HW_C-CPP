#include <stdio.h>

int main() {
    float T;
    T = 365.0 + 1 / (4 + 1 / (7 + 1 / (1 + 1 / 3.0)));
    printf("T = %f\n", T);
}