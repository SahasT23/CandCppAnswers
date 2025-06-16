// Memory Allocation Checker 

// Good method for debugging and checking allocation. much betetr than error messages from the compiler.
// Also forces some learning of the std library.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No numbers provided!\n");
        return 1;
    }
    
    int *numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (!numbers) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        *(numbers + (i - 1)) = atoi(argv[i]);
        sum += *(numbers + (i - 1));
    }
    
    printf("Numbers: ");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", *(numbers + i));
    }
    printf("\nSum: %d\n", sum);
    
    free(numbers);
    return 0;
}