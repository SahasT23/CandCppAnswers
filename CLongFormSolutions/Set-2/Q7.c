// Pointer Sort 

/**
 * Crucial apsect of the assessment. 
 * covers the whole 'swapping' aspect that can be applied using pointers. 
 * Somewhat similar to previous implementations
 */

#include <stdio.h>
#include <stdlib.h>

void pointerSort(int *arr, int n) {
    int *i, *j, temp;
    for (i = arr; i < arr + n - 1; i++) {
        for (j = i + 1; j < arr + n; j++) {
            if (*i > *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    
    pointerSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    
    free(arr);
    return 0;
}