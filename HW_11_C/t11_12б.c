#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t name_length;
    char *name;
    float price;
    size_t age_range_length;
    char *age_range;
} Toy;

int is_within_age_range(const char *age_range, int n, int m) {
    int min_age, max_age;
    if (sscanf(age_range, "from %d to %d years", &min_age, &max_age) == 2) {
        return (n >= min_age && m <= max_age);
    }
    return 0;
}

int main() {
    FILE *file = fopen("HW_11_C/t11_12.bin", "rb");
    if (!file) {
        printf("Failed to open the file for reading!\n");
        return 1;
    }

    int n, m;
    printf("Enter minimum age (n): ");
    scanf("%d", &n);
    printf("Enter maximum age (m): ");
    scanf("%d", &m);

    while (!feof(file)) {
        Toy toy;

        if (fread(&toy.name_length, sizeof(size_t), 1, file) != 1) break;
        toy.name = (char*)malloc(toy.name_length + 1);
        if (fread(toy.name, sizeof(char), toy.name_length, file) != toy.name_length) break;
        toy.name[toy.name_length] = '\0';

        if (fread(&toy.price, sizeof(float), 1, file) != 1) break;

        if (fread(&toy.age_range_length, sizeof(size_t), 1, file) != 1) break;
        toy.age_range = (char*)malloc(toy.age_range_length + 1);
        if (fread(toy.age_range, sizeof(char), toy.age_range_length, file) != toy.age_range_length) break;
        toy.age_range[toy.age_range_length] = '\0';

        if (is_within_age_range(toy.age_range, n, m)) {
            printf("Toy name: %s\n", toy.name);
            printf("Price: %.2f UAH\n", toy.price);
            printf("Age range: %s\n", toy.age_range);
            printf("\n");
        }

        free(toy.name);
        free(toy.age_range);
    }

    fclose(file);
    return 0;
}
