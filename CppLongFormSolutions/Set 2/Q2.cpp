// Linked list, bit difficult

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        while (head != nullptr) {
            popFront();
        }
    }

    void pushFront(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void popFront() {
        if (head == nullptr) return; // no node to pop
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);

    list.printList(); // should print 30 20 10

    list.popFront();
    list.printList(); // should print 20 10

    return 0;
}