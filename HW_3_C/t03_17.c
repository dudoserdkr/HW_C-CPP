#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void find_square_cond(int square[4][2], int ptr[2][2]) {
    int x = square[0][0], y = square[0][1];
    int x1 = 0, y1 = 0;

    for (int i = 0; i < 4; i++) {
        x1 = square[i][0];
        y1 = square[i][1];

        if (x != x1 && y != y1) {
            break;
        }
    }

    ptr[0][0] = x > x1 ? x1 : x;
    ptr[0][1] = y > y1 ? y1 : y;
    ptr[1][0] = x1 > x ? x1 : x;
    ptr[1][1] = y1 > y ? y1 : y;
}

bool dot_inside_square(int square[4][2], int ptr[2][2]) {
    int x, y;

    for (int i = 0; i < 4; i++) {
        x = square[i][0];
        y = square[i][1];

        if ((ptr[0][0] < x && x < ptr[1][0]) && (ptr[0][1] < y && y < ptr[1][1])) {
            return true;
        }
    }
    return false;
}

void generate_square(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, int* x4, int* y4, int side_length) {
    int start_x = rand() % 10;
    int start_y = rand() % 10;

    *x1 = start_x;
    *y1 = start_y;

    *x2 = start_x;
    *y2 = start_y + side_length;

    *x3 = start_x + side_length;
    *y3 = start_y + side_length;

    *x4 = start_x + side_length;
    *y4 = start_y;
}

int main() {
    int ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4;
    int bx1, by1, bx2, by2, bx3, by3, bx4, by4;

    scanf("%d %d %d %d %d %d %d %d", &ax1, &ay1, &ax2, &ay2, &ax3, &ay3, &ax4, &ay4);
    scanf("%d %d %d %d %d %d %d %d", &bx1, &by1, &bx2, &by2, &bx3, &by3, &bx4, &by4);

    int square[4][2] = {{ax1, ay1}, {ax2, ay2}, {ax3, ay3}, {ax4, ay4}};
    int square1[4][2] = {{bx1, by1}, {bx2, by2}, {bx3, by3}, {bx4, by4}};

    int ptr[2][2];

    find_square_cond(square, ptr);

    if (dot_inside_square(square1, ptr)) {
        int x, y;

        for (int i = 0; i < 4; i++) {
            x = square1[i][0];
            y = square1[i][1];

            if ( (ptr[0][0] < x && x < ptr[1][0]) ^ (ptr[0][1] < y && y < ptr[1][1]) ) {
                printf("%d %d\n", x, y);
            }
        }
    } else {
        printf("Dot is not inside the square\n");
    }
}