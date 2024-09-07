#include <stdio.h>
#include <math.h>

int main() {
    char c;
    printf("Enter a f if float or enter an i if int: ");
    scanf("%c", &c);
    if (c == 'f') {
        float n;
        scanf("%f", &n);
        float log10_n = log10f(n);
        printf("%.2f\n", log10_n);
    }
    else if (c == 'i') {
        int n;
        scanf("%d", &n);
        int log10_n = log10(n);
        printf("%.2i\n", log10_n);
    }
}