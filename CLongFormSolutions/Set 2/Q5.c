#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *myStrDup(const char *src) {
    char *dest = (char *)malloc(strlen(src) + 1);
    if (!dest) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    char *temp = dest;
    while (*src) {
        *temp++ = *src++;
    }
    *temp = '\0';
    return dest;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    char *dup = myStrDup(str);
    if (dup) {
        printf("Original string: %s\n", str);
        printf("Duplicated string: %s\n", dup);
        free(dup);
    }
    
    return 0;
}