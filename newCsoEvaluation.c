#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int real;
    int imaginary;
} complex;

complex **allocateMemoryToMatrix(int rows, int columns) {
    complex **matrix = (complex **)malloc(rows * sizeof(complex *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (complex *)malloc(columns * sizeof(complex));
    }
    return matrix;
}

void freeMatrix(complex **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// void readMatrixFromFile(FILE *file, complex **matrix, int rows, int columns) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             fscanf(file, "%d,%d", &matrix[i][j].real, &matrix[i][j].imaginary);
//         }
//     }
// }

void readMatrixFromFile(complex **c1, int rows , int column)
{
    // complex c2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d,%d", &c1[i][j].real , &c1[i][j].imaginary);
        }
    }
}

void writeMatrixToFile(complex **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d,%d ", matrix[i][j].real, matrix[i][j].imaginary);
        }
        printf("\n");
    }
}

void multiplyMatrices(complex **matrix1, int rows1, int columns1,
                      complex **matrix2, int rows2, int columns2,
                      complex **result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j].real = 0;
            result[i][j].imaginary = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j].real += matrix1[i][k].real * matrix2[k][j].real -
                                     matrix1[i][k].imaginary * matrix2[k][j].imaginary;
                result[i][j].imaginary += matrix1[i][k].real * matrix2[k][j].imaginary +
                                          matrix1[i][k].imaginary * matrix2[k][j].real;
            }
        }
    }
}

int main() {
    int rows1, columns1, rows2, columns2;
    FILE *fileInput1, *fileInput2, *fileOutput;

    // Open the input and output files
    fileInput1 = fopen("input1.txt", "r");
    fileInput2 = fopen("input2.txt", "r");
    fileOutput = fopen("output.txt", "w");

    if (fileInput1 == NULL || fileInput2 == NULL || fileOutput == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    // Read the matrix sizes from the input files
    scanf("%d %d", &rows1, &columns1);
    scanf("%d %d", &rows2, &columns2);

    // Check if matrix multiplication is possible
    if (columns1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    // Allocate memory for matrices
    complex **matrix1 = allocateMemoryToMatrix(rows1, columns1);
    complex **matrix2 = allocateMemoryToMatrix(rows2, columns2);
    complex **result = allocateMemoryToMatrix(rows1, columns2);

    // Read matrices from input files
    readMatrixFromFile(matrix1, rows1, columns1);
    readMatrixFromFile(matrix2, rows2, columns2);

    // Perform matrix multiplication
    multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2, result);

    // Write the result to the output file
    writeMatrixToFile(result, rows1, columns2);

    // Free memory and close files
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, rows1);

    fclose(fileInput1);
    fclose(fileInput2);
    fclose(fileOutput);

    printf("Matrix multiplication completed successfully.\n");

    return 0;
}
