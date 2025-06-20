// ADVANCED QUESTION. DON'T DO THIS RIGHT NOW

/*
Intorducing functions, a bit more advanced and also logical operators have been introduced.
Also decided to introduce recursion (more advanced concept, but it is a bit more difficult, probably 
should add some hints for the solution).
Also introduced the concept of error handling -- shown in "Error: Please enter a non-negative number"
*/

#include <stdio.h>

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1); // takes previous input and then uses it for the calculation
}

int main() {
    int num;
    
    // Input validation using do-while loop
    do {
        printf("Enter a non-negative integer: ");
        scanf("%d", &num);
        
        if (num < 0) {
            printf("Error: Please enter a non-negative number!\n");
        }
    } while (num < 0);
    
    // Calculate and display factorial
    printf("Factorial of %d = %llu\n", num, factorial(num));
    
    return 0;
}