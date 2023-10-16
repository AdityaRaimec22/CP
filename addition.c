#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int columns) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int rows1, int columns1, int** matrix2, int rows2, int columns2) {
    // Check if the matrices can be multiplied
    if (columns1 != rows2) {
        printf("Error: Matrices cannot be multiplied!\n");
        return NULL;
    }

    // Allocate memory for the result matrix
    int** result = allocateMatrix(rows1, columns2);

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, columns1, rows2, columns2;

    // Get the size of the first matrix
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &columns1);

    // Get the size of the second matrix
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &columns2);

    // Check if matrices can be multiplied
    if (columns1 != rows2) {
        printf("Error: Matrices cannot be multiplied!\n");
        return 0;
    }

    // Allocate memory for the matrices
    int** matrix1 = allocateMatrix(rows1, columns1);
    int** matrix2 = allocateMatrix(rows2, columns2);

    // Get matrix elements from the user
    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    int** result = multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2);

    if (result != NULL) {
        printf("Matrix multiplication result:\n");
        displayMatrix(result, rows1, columns2);
    }

    // Free memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, rows1);

    return 0;
}
