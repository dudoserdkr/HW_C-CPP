#include <stdio.h>
#include <stdlib.h>

typedef struct People_population {
    long int population;
    int country_square;
} People_population;

int find_min_population_density(People_population *people, int N) {
    int min_density = people[0].population / people[0].country_square;
    int min_density_index = 0;
    for (int i = 1; i < N; i++) {
        int density = people[i].population / people[i].country_square;
        if (density < min_density) {
            min_density = density;
            min_density_index = i;
        }
    }
    return min_density_index;
}

int main() {
    int N;
    printf("Input N: ");
    scanf("%d", &N);
    People_population *people = (People_population*)malloc(N * sizeof(People_population));
    for (int i = 0; i < N; i++) {
        printf("Input population and country square: ");
        scanf("%ld %d", &people[i].population, &people[i].country_square);
    }
    int min_density_index = find_min_population_density(people, N);
    float density = (float)people[min_density_index].population / people[min_density_index].country_square;
    printf(
        "Country with index %d has the minimum population density: %f\n", min_density_index, density);
}