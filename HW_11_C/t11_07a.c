// 11_07a 11_12b

#include <stdio.h>

int main() {
    FILE *file;
    char buffer[256];

    file = fopen("HW_11_C/t11_07.bin", "rb");

    if (!file) {
        printf("Error opening file\n");
    }

    double num;

    double sum = 0;

    while (fread(&num, sizeof(double), 1, file)) {
        sum += num;
    }
    fclose(file);

    printf("%lf\n", sum);
}
