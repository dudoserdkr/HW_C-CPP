#include <stdio.h>
#include <math.h>

double exp_x2(int x) {
    return exp(-x * x);
}

int main() {
    printf("x---|-1--|-2--|-3--|-4--|-5--|\n");
    printf("----|----|----|----|----|----|\n");
    printf("F(x)|%.2f|%.2f|%.2f|%.2f|%.2f|\n", exp_x2(1), exp_x2(2), exp_x2(3), exp_x2(4), exp_x2(5));
}