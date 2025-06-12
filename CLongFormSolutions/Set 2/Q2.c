// Dynamic Array Solution

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int capacity = 1, count = 0;
    int num;
    
    arr = (int *)malloc(capacity * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter integers (negative number to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0) break;
        
        if (count >= capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (!arr) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }
        
        *(arr + count) = num;
        count++;
    }
    
    printf("Entered numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    
    free(arr);
    return 0;
}