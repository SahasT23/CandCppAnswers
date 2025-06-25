// Q1

#include <stdio.h>

int main() {
    int val = 100;
    int *ptr = &val;  // ❌ Was uninitialized; dereferencing caused undefined behavior
    printf("Value: %d\n", *ptr); 
    return 0;
}

//===================================================================

// Q2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr); // ✅ Good practice to use the value
    free(ptr); // ❌ Was missing; not freeing heap memory causes leaks
    return 0; 
}

//===================================================================

// Q3

#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;
    // ❌ ptr = ptr + 3; → Points to garbage beyond `num`
    printf("Address: %p\n", (void*)ptr); // Now prints actual valid address
    return 0;
}

//===================================================================

// Q4

#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    printf("Third element: %d\n", arr[2]); // ❌ arr[3] is out-of-bounds (0-based indexing)
    return 0;
}

//===================================================================

// Q5

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    free(ptr);
    // ❌ Second free leads to undefined behavior
    // free(ptr);  // Removed to prevent double-free
    return 0;
}

//===================================================================

// Q6

#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *ptr = &arr[0][0]; // ❌ Originally assigned a 2D array to 1D pointer
    printf("%d\n", *ptr);  // ✅ Now correctly prints arr[0][0]
    return 0;
}

//===================================================================

// Q7

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 99;
    free(ptr); 
    // ❌ Accessing memory after free is undefined behavior
    // printf("%d\n", *ptr); // Commented out to prevent use-after-free
    return 0;
}

//===================================================================

// Q8

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix;
    matrix = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        matrix[i] = (int*)malloc(3 * sizeof(int)); // ❌ Was malloc(3), should allocate enough for 3 integers
    }

    // Freeing the memory (good habit)
    for (int i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

//===================================================================