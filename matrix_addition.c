#include <stdio.h>
#include <stdlib.h>

int **allocateMemoryToMatrix(int column, int rows)
{
    int **matrix = (int **)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }
    return matrix;
}

void **InputMatrix(int **matrix, int rows, int column)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrix(int **matrix1, int **matrix2, int **sum, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int rows, int colums)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, columns;
    printf("enter the number of rows: ");
    scanf("%d", &rows);

    printf("enter the number of columns: ");
    scanf("%d", &columns);

    int **matrix1 = allocateMemoryToMatrix(columns, rows);
    int **matrix2 = allocateMemoryToMatrix(columns, rows);
    int **sum = allocateMemoryToMatrix(columns, rows);

    InputMatrix(matrix1, rows, columns);
    InputMatrix(matrix2, rows, columns);

    addMatrix(matrix1, matrix2, sum, rows, columns);

    printMatrix(sum, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(sum[i]);
    }
    free(matrix1);
    free(matrix2);
    free(sum);

    return 0;
}