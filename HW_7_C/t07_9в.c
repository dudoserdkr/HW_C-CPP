#include<stdio.h>
#include<stdint.h>

int main() {
// a1, a2, a3, ... , an
// program -> max(a2, a4,...)

    unsigned int n;
    scanf("%u", &n);
    uint32_t a[n];
    for (int i = 0; i < n; i++) {
        scanf("%u", &a[i]);
    }
    uint32_t max = a[1];
    for (int i = 3; i < n; i+=2) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("%u", max);
}