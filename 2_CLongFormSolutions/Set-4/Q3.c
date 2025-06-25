// Bubble Sort, bit harder to understand, but once you know how the variables are swapped and the logic behind it, then you're fine.

#include <stdio.h>

/* 
Thought Process:
1. Bubble sort repeatedly compares adjacent elements and swaps them if out of order.
2. After each pass, the largest unsorted element "bubbles" to the end.
3. Algorithm: Use nested loops; outer loop for passes, inner loop for comparisons/swaps.
*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter array size (max 10): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 10) {
        printf("Invalid array size!\n");
        return 1;
    }
    
    int arr[10];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}