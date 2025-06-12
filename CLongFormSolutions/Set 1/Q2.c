#include <stdio.h>

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
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