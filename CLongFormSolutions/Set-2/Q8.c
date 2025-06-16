// Dynamic Buffer - Advanced

/**
 * Buffers are a difficult concept to cover, soemthing they can try later on. 
 * Also covers files, which is a bit more advanced but they can still try it. 
 * Not necessary. 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s!\n", filename);
        return 1;
    }
    
    char *buffer = NULL;
    int capacity = 1, size = 0;
    buffer = (char *)malloc(capacity * sizeof(char));
    if (!buffer) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }
    
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            buffer = (char *)realloc(buffer, capacity * sizeof(char));
            if (!buffer) {
                printf("Memory reallocation failed!\n");
                fclose(file);
                return 1;
            }
        }
        *(buffer + size) = (char)c;
        size++;
    }
    *(buffer + size) = '\0';
    
    fclose(file);
    
    printf("File contents:\n%s\n", buffer);
    
    free(buffer);
    return 0;
}