#include <iostream>
#include <string>

// Q1

int number = 25; // Fixed: assigning an integer literal instead of a string

// Q2

int x = 7;
if (x == 10) // Fixed: use '==' for comparison, not '=' which is assignment
    std::cout << "x is ten";

// Q3

for (int i = 0; i < 5; i++) // Fixed: added parentheses around loop declaration
    std::cout << i << std::endl;

// Q4

int main() { // Fixed: specify return type 'int' for main
    std::cout << "Hello!";
    return 0;
}

// Q5

int a = 0; // Fixed: initialize 'a' before use
int result = a + 2;

// Q6

int max(int a, int b) { // Fixed: specify types for both parameters
    return (a > b) ? a : b;
}

// Q7

int total = 50; // Fixed: declare and initialize before using
std::cout << total << std::endl;

// Q8

int i = 0;
++i; // Safer to use pre-increment separately if clarity is important
int result = i + i; 
std::cout << result; // Fixed: avoids undefined sequencing with i++ + ++i





