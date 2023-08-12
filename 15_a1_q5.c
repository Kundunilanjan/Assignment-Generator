5.Write a program in C to represent a sparse matrix of order n x n efficient way in respect of space.
                                  code
#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix {
    int n;
    int *values;
    int *row_ptr;
    int *col_index;
};

struct SparseMatrix* createSparseMatrix(int n, int numNonZero) {
    struct SparseMatrix *matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    matrix->n = n;
    matrix->values = (int*)malloc(numNonZero * sizeof(int));
    matrix->row_ptr = (int*)malloc((n + 1) * sizeof(int));
    matrix->col_index = (int*)malloc(numNonZero * sizeof(int));
    return matrix;
}

void insertNonZero(struct SparseMatrix *matrix, int row, int col, int value, int *current) {
    matrix->values[*current] = value;
    matrix->col_index[*current] = col;
    while (row > *current) {
        matrix->row_ptr[*current] = *current;
        (*current)++;
    }
}

void finalizeInsertion(struct SparseMatrix *matrix, int numNonZero) {
    while (numNonZero > matrix->row_ptr[matrix->n]) {
        matrix->row_ptr[matrix->n] = numNonZero;
    }
}

void displaySparseMatrix(struct SparseMatrix *matrix) {
    int current = 0;
    for (int i = 0; i < matrix->n; i++) {
        for (int j = 0; j < matrix->n; j++) {
            if (j == matrix->col_index[current] && current < matrix->row_ptr[i + 1]) {
                printf("%d ", matrix->values[current]);
                current++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void freeSparseMatrix(struct SparseMatrix *matrix) {
    free(matrix->values);
    free(matrix->row_ptr);
    free(matrix->col_index);
    free(matrix);
}

int main() {
    int n = 4;
    int numNonZero = 5;
    struct SparseMatrix *matrix = createSparseMatrix(n, numNonZero);

    int current = 0;
    insertNonZero(matrix, 0, 1, 2, &current);
    insertNonZero(matrix, 1, 0, 1, &current);
    insertNonZero(matrix, 2, 2, 3, &current);
    insertNonZero(matrix, 3, 1, 4, &current);
    insertNonZero(matrix, 3, 3, 5, &current);

    finalizeInsertion(matrix, numNonZero);

    printf("Sparse Matrix:\n");
    displaySparseMatrix(matrix);

    freeSparseMatrix(matrix);

    return 0;
}
