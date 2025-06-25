// Pointer Array Reversal Answer

/*
Bit more difficult, gets around the concept of pointers very easily,
Difficult to accept conceptually.
*/

#include <stdio.h>

// Function to reverse the elements of an array
void reverseArray(int *arr, int n) {
    // Initialise pointer to the beginning of the array
    int *start = arr;
    // Initialise pointer to the end of the array
    int *end = arr + n - 1;
    // Temporary variable for swapping elements
    int temp;
    
    // Swap elements from start and end until pointers meet
    while (start < end) {
        // Store the start element in temp
        temp = *start;
        // Replace start element with end element
        *start = *end;
        // Replace end element with temp variable (original start element)
        *end = temp;
        // Move start pointer forward
        start++;
        // Move end pointer backward
        end--;
    }
}

int main() {
    // Variable to store the size of the array
    int n;
    // Prompt user for array size
    printf("Enter the size of the array: ");
    // Read array size from user input
    scanf("%d", &n);
    
    // Check if array size is valid (non-positive sizes are invalid)
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1; // Exit with error code
    }
    
    // Declare array of size n
    int arr[n];
    // Prompt user to enter array elements
    printf("Enter %d integers:\n", n);
    // Loop to read n integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Call function to reverse the array
    reverseArray(arr, n);
    
    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    // Print newline for tidy output
    printf("\n");
    
    // Indicate successful programme execution
    return 0;
}