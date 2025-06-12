// Integer

#include <iostream>

int main() {
    int capacity = 2;
    int size = 0;
    int* data = new int[capacity];

    int value;
    // Continuously read integers
    while (std::cin >> value) {
        // Check if we need more space
        if (size == capacity) {
            // Allocate a new array with double capacity
            int newCapacity = capacity * 2;
            int* newData = new int[newCapacity];

            // Copy old data
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            // Free old array and update pointers
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        // Store the new value
        data[size++] = value;
    }

    // Print the integers read
    std::cout << "Integers read: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Free memory
    delete[] data;
    data = nullptr;

    return 0;
}