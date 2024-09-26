#include<stdint.h>
#include<stdio.h>
#include<math.h>

int is_prime(uint32_t n) {
    if (n == 1) {
        return 0;
    }
    for (uint32_t i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    uint32_t N, counter = 0;
    scanf("%u", &N);
    uint32_t arr[N];
    for (uint32_t i = 0; i < N; i++) {
        scanf("%u", &arr[i]);
    }

    for (uint32_t i = 0; i < N; i++) {
        if (is_prime(arr[i])) {
            counter++;
        }
    }
    printf("%u\n", counter);
}