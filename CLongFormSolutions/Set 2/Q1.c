// Pointer Array Reversal Answer

#include <stdio.h>

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    int temp;
    
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
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
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    reverseArray(arr, n);
    
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}