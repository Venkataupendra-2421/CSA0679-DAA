#include <stdio.h>

#define ROWS 3
#define COLS 3

void multiplyMatrices(int first[][COLS], int second[][COLS], int result[][COLS]);

int main() {
    int first[ROWS][COLS], second[ROWS][COLS], result[ROWS][COLS];
    int i, j;

    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    multiplyMatrices(first, second, result);

    printf("Product of the matrices:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void multiplyMatrices(int first[][COLS], int second[][COLS], int result[][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

