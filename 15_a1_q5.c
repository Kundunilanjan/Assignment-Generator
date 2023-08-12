5. Write a program in C to represent a sparse matrix of order n x n
efficient way in respect of space.
                             code
#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix {
    int *values;
    int *row_indices;
    int *column_indices;
    int size;  // Number of non-zero elements
    int n;     // Order of the matrix
};

struct SparseMatrix* createSparseMatrix(int n, int size) {
    struct SparseMatrix *matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    if (!matrix) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    matrix->n = n;
    matrix->size = size;

    matrix->values = (int*)malloc(size * sizeof(int));
    matrix->row_indices = (int*)malloc(size * sizeof(int));
    matrix->column_indices = (int*)malloc(size * sizeof(int));

    return matrix;
}

void insertElement(struct SparseMatrix *matrix, int row, int col, int value) {
    if (matrix->size >= matrix->n * matrix->n) {
        printf("Sparse matrix is already full.\n");
        return;
    }

    matrix->values[matrix->size] = value;
    matrix->row_indices[matrix->size] = row;
    matrix->column_indices[matrix->size] = col;
    matrix->size++;
}

int getElement(struct SparseMatrix *matrix, int row, int col) {
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->row_indices[i] == row && matrix->column_indices[i] == col) {
            return matrix->values[i];
        }
    }
    return 0;  // Default value for non-existing element
}

void printSparseMatrix(struct SparseMatrix *matrix) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < matrix->n; i++) {
        for (int j = 0; j < matrix->n; j++) {
            printf("%d\t", getElement(matrix, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 5;  // Order of the matrix
    int num_non_zero = 5;  // Number of non-zero elements

    struct SparseMatrix *sparseMatrix = createSparseMatrix(n, num_non_zero);

    insertElement(sparseMatrix, 0, 1, 2);
    insertElement(sparseMatrix, 1, 2, 5);
    insertElement(sparseMatrix, 2, 0, 9);
    insertElement(sparseMatrix, 3, 3, 7);
    insertElement(sparseMatrix, 4, 1, 3);

    printSparseMatrix(sparseMatrix);

    free(sparseMatrix->values);
    free(sparseMatrix->row_indices);
    free(sparseMatrix->column_indices);
    free(sparseMatrix);

    return 0;
}
