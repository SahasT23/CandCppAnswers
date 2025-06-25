// Advanced Data structure
/*
Linked lists are quite advanced, but it builds on a lot of concepts on memory. 
Moving away from the contiguous memory model of an array. 

This is an advanced question, but it will be really good practice
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node *current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int value;
    
    printf("Enter integers (negative number to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value < 0) break;
        insertAtEnd(&head, value);
    }
    
    printf("Linked List: ");
    printList(head);
    
    // Free memory
    struct Node *current = head;
    while (current) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}