/*
Introducing global and local scope with this question.
Students should be able to understand how the global variable is used and referenced in main. 
*/ 

#include <stdio.h>

// Global variable
int globalCounter = 0;

void incrementGlobal() {
    // Modify global variable
    globalCounter++;
    printf("In incrementGlobal: globalCounter = %d\n", globalCounter);
}

void localCounterFunction() {
    // Local variable
    int localCounter = 0;
    localCounter++;
    printf("In localCounterFunction: localCounter = %d, globalCounter = %d\n", 
           localCounter, globalCounter);
}

int main() {
    // Initial state
    printf("Initial: globalCounter = %d\n", globalCounter);
    
    // Call functions multiple times to demonstrate
    incrementGlobal();
    localCounterFunction();
    incrementGlobal();
    localCounterFunction();
    
    // Final state
    printf("Final: globalCounter = %d\n", globalCounter);
    
    return 0;
}