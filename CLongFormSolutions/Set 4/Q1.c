// Linear Search

#include <stdio.h>

/* 
Thought Process:
1. Linear search checks each element in the array sequentially until the target is found or the end is reached.
2. Return the index if found, otherwise return -1.
3. Algorithm: Iterate through array from index 0 to n-1, compare each element with target.
*/
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index where target is found
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
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter target value: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, n, target);
    if (result == -1) {
        printf("Target %d not found in array.\n", target);
    } else {
        printf("Target %d found at index %d.\n", target, result);
    }
    
    return 0;
}