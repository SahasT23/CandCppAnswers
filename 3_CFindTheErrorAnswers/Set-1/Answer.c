// Q1

#include <stdio.h>

int main() {
    printf("Hello, World!"); // ❌ Missing semicolon after this line
    return 0;
}

//===================================================================

// Q2

#include <stdio.h>

int main() {
    int age = 25;  // ❌ "25" is a string; 25 should be an integer literal
    printf("Age: %d\n", age);
    return 0;
}

//===================================================================

// Q3

#include <stdio.h>

int checkNumber(int num) {
    if (num > 0)
        printf("Positive\n");
    else
        printf("Negative or Zero\n");

    return 0; // ❌ Function of type int must return an int
}

//===================================================================

// Q4

#include <stdio.h>

int main() {
    int num = 10;
    printf("Value: %d\n", num); // ❌ %f expects a float/double, not int
    return 0;
}

//===================================================================

// Q5

#include <stdio.h>

int main() {
    int x = 0; // ❌ 'x' was uninitialized; using uninitialized values causes undefined behavior
    printf("Value of x: %d\n", x); 
    return 0;
}

//===================================================================

// Q6

#include <stdio.h>

int main() {
    int i = 0;
    while (i < 5) {
        printf("Iteration %d\n", i);
        i++; // ❌ Missing increment: loop would run infinitely
    }
    return 0;
}

//===================================================================

// Q7

#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    printf("Fourth element: %d\n", arr[2]); // ❌ arr[3] is out of bounds; indices go from 0 to 2
    return 0;
}

//===================================================================