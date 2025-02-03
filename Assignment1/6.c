#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int **matrix, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int** transpose(int **matrix, int rows, int cols) {
    int **result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
        for (int j = 0; j < rows; j++)
            result[i][j] = matrix[j][i];
    }
    return result;
}

int main() {
    int rows = 3, cols = 4;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));

    fillMatrix(matrix, rows, cols);
    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    int **transposed = transpose(matrix, rows, cols);
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    // Free memory
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    for (int i = 0; i < cols; i++) free(transposed[i]);
    free(transposed);

    return 0;
}