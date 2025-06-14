// Binary Search, simpler and don't have to think about memory as much.

#include <stdio.h>

/* 
Thought Process:
1. Binary search requires a sorted array and divides the search space in half each iteration.
2. Compare target with middle element, then search left or right half based on comparison.
3. Algorithm: Maintain left and right pointers, calculate mid, adjust pointers until target is found or left > right.
*/
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
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
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter target value: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, n, target);
    if (result == -1) {
        printf("Target %d not found in array.\n", target);
    } else {
        printf("Target %d found at index %d.\n", target, result);
    }
    
    return 0;
}