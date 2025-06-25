// String conceatenation method
// Basically combining two strings together. student will have to think a lot about arrays and memopry allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatStrings(const char *s1, const char *s2) {
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (!result) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    char *temp = result;
    while (*s1) {
        *temp++ = *s1++;
    }
    while (*s2) {
        *temp++ = *s2++;
    }
    *temp = '\0';
    
    return result;
}

int main() {
    char s1[100], s2[100];
    
    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    if (s1[strlen(s1) - 1] == '\n') {
        s1[strlen(s1) - 1] = '\0';
    }
    
    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    if (s2[strlen(s2) - 1] == '\n') {
        s2[strlen(s2) - 1] = '\0';
    }
    
    char *result = concatStrings(s1, s2);
    if (result) {
        printf("Concatenated string: %s\n", result);
        free(result);
    }
    
    return 0;
}