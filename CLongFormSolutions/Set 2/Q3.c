// Matrix Allocation Program
// Fairly simple, very similar to EEE2021 Semester 2 coursework

#include <stdlib.h>

int main() {
    int m, n;
    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);
    
    if (m <= 0 || n <= 0) {
        printf("Invalid dimensions!\n");
        return 1;
    }
    
    // Allocate array of pointers for rows
    int **matrix = (int **)malloc(m * sizeof(int *));
    if (!matrix) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Allocate each row
    // Basically like a 2D matrix, hence the i and m
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (!matrix[i]) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    
    // Read matrix elements
    printf("Enter %d x %d matrix elements:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print matrix, output
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}