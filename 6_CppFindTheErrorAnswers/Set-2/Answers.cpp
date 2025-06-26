#include <iostream>
#include <cstdlib> // For malloc and free 


// Q1

int *ptr = new int; // Allocate memory first
*ptr = 10; // Dereference after allocation

//==================================================================

// Q2

#include <cstdlib> // Include for malloc and free
int *arr = (int*) malloc(5 * sizeof(int)); // Allocate memory for 5 integers
arr[0] = 10; // Initialize first element
free(arr); // Also add: cleanup memory after use

//===================================================================

// Q3

int *p = new int; // Allocate single element
delete p; // Use delete without brackets for single element

//===================================================================

// Q4

int *data = new int(42); // Allocate memory and initialize
delete data; // Free allocated memory
// Avoid using 'data' after it's deleted

//===================================================================

// Q5

int x = 100; // Stack-allocated variable
// Do not use free() on stack-allocated memory

//===================================================================

// Q6

int *ptr = new int(10); // Allocate memory and initialize
delete ptr;           // Free previous allocation
ptr = new int(20); // Reassign to new memory
// Use delete before reassigning to avoid memory leak

//===================================================================

// Q7

int *p = new int; // Allocate memory before dereferencing
*p = 5; // Dereference after allocation

//===================================================================

// Q8

int *arr = (int*) malloc(3 * sizeof(int)); // Allocate memory
int *temp = (int*) realloc(arr, 6 * sizeof(int)); // Reallocate memory
if (temp == NULL) // Check if realloc was successful
    std::cout << "Reallocation failed"; // Handle failure case
else
    arr = temp; // Update 'arr' only if realloc was successful
// Always check if realloc was successful before using 'arr'

//===================================================================
