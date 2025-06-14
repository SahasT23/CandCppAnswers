// Prime Check Program
/*
Adds some for loop content to reinforce their learning
*/

#include <stdio.h>

int isPrime(int num) {
    // Handle edge cases
    if (num <= 1) {
        return 0; // Not prime
    }
    if (num == 2) {
        return 1; // 2 is prime
    }
    if (num % 2 == 0) {
        return 0; // Even numbers > 2 are not prime
    }

    // Check odd divisors up to square root of num
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

int main() {
    int number;

    // Prompt user for input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Validate input
    if (number < 0) {
        printf("Please enter a non-negative number!\n");
        return 1;
    }

    // Check if number is prime and display result
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}