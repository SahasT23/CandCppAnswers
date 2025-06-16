/*
Introducing void types, again, a bit more advanced.
This is a lot more difficult, students need to think carefully about what is going on. 
I have included annotations for this as it is a bit more conceptually different. 

*/

#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str); // Initialisation of variables that we will use
    int i, j;
    char temp;
    
    // Swap characters from start and end moving towards center
    for (i = 0, j = length - 1; i < j; i++, j--) {  // i and j for starting from the start and end, iterating through with a for-loop
        temp = str[i];
        str[i] = str[j]; // swapping the indices.
        str[j] = temp;
    }
}

int main() {  // Main method to run the program and prompt the user for input
    char str[100];
    
    // Read string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Reverse the string (function call concept)
    reverseString(str);
    
    // Print reversed string
    printf("Reversed string: %s\n", str); // output
    
    return 0;
}