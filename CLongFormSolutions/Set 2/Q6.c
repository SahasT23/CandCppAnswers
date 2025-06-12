#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void splitString(const char *str, char delim, char **first, char **second) {
    *first = *second = NULL;
    const char *p = str;
    int delimIndex = -1;
    
    // Find delimiter position
    while (*p && *p != delim) {
        delimIndex++;
        p++;
    }
    
    if (*p == delim) {
        // Allocate memory for first part
        *first = (char *)malloc(delimIndex + 1);
        if (!*first) {
            printf("Memory allocation failed!\n");
            return;
        }
        // Copy first part
        for (int i = 0; i < delimIndex; i++) {
            (*first)[i] = str[i];
        }
        (*first)[delimIndex] = '\0';
        
        // Allocate memory for second part
        *second = (char *)malloc(strlen(str) - delimIndex);
        if (!*second) {
            printf("Memory allocation failed!\n");
            free(*first);
            *first = NULL;
            return;
        }
        // Copy second part
        p++;
        char *temp = *second;
        while (*p) {
            *temp++ = *p++;
        }
        *temp = '\0';
    }
}

int main() {
    char str[100], delim;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    printf("Enter delimiter character: ");
    scanf(" %c", &delim);
    
    char *first = NULL, *second = NULL;
    splitString(str, delim, &first, &second);
    
    if (first && second) {
        printf("First part: %s\n", first);
        printf("Second part: %s\n", second);
        free(first);
        free(second);
    } else {
        printf("Delimiter not found or memory allocation failed!\n");
    }
    
    return 0;
}