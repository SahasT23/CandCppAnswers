// Selection Sort

/*
One of the harder sort methods, but it is good to know. Might need to add some of my computer science stuff to this part of the teaching material. 
*/

#include <stdio.h>

/* 
Thought Process:
1. Selection sort finds the minimum element in the unsorted portion and places it at the beginning.
2. Repeat until the entire array is sorted.
3. Algorithm: Outer loop iterates through array, inner loop finds minimum, swap if needed.
*/
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
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
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}