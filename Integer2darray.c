#include <stdio.h>
#include <stdbool.h>

void readMatrix(int n, int matrix[][n]);
void displayMatrix(int n, int matrix[][n]);
void calculateRowTotals(int n, int matrix[][n], int rowTotals[]);
bool isIdentityMatrix(int n, int matrix[][n]);

int main() {
    int n;
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);

    int matrix[n][n];
    int rowTotals[n];

    printf("Enter elements of the matrix:\n");
    readMatrix(n, matrix);

    printf("Matrix you entered:\n");
    displayMatrix(n, matrix);

    calculateRowTotals(n, matrix, rowTotals);
    printf("Row totals:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: %d\n", i + 1, rowTotals[i]);
    }

    if (isIdentityMatrix(n, matrix)) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    return 0;
}

void readMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateRowTotals(int n, int matrix[][n], int rowTotals[]) {
    for (int i = 0; i < n; i++) {
        rowTotals[i] = 0;
        for (int j = 0; j < n; j++) {
            rowTotals[i] += matrix[i][j];
        }
    }
}

bool isIdentityMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}
