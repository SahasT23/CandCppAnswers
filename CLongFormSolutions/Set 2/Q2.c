// Dynamic Array Solution
/*
Pointers with for loops, fairly simple bu talso introduce some dynamism. 
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Main function to dynamically allocate and manage an array of integers
int main() {
    // Pointer to the dynamic array, initially set to NULL
    int *arr = NULL;
    // Initial capacity of the array and count of elements
    int capacity = 1, count = 0;
    // Variable to store user input
    int num;
    
    // Allocate initial memory for the array (allocating it for each index in our array)
    arr = (int *)malloc(capacity * sizeof(int));
    // Check if memory allocation was successful
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error code
    }
    
    // Prompt user to enter integers
    printf("Enter integers (negative number to stop):\n");
    // Loop to read integers until a negative number is entered
    while (1) {
        scanf("%d", &num);
        // Break the loop if a negative number is entered
        if (num < 0) break;
        
        // Check if the array needs to be resized
        if (count >= capacity) {
            // Double the capacity
            capacity *= 2;
            // Reallocate memory with the new capacity
            arr = (int *)realloc(arr, capacity * sizeof(int));
            // Check if memory reallocation was successful
            if (!arr) {
                printf("Memory reallocation failed!\n");
                return 1; // Exit with error code
            }
        }
        
        // Store the input number in the array
        *(arr + count) = num;
        // Increment the count of elements
        count++;
    }
    
    // Print the entered numbers
    printf("Entered numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(arr + i));
    }
    // Print newline for tidy output
    printf("\n");
    
    // Free the dynamically allocated memory
    free(arr);
    // Indicate successful programme execution
    return 0;
}