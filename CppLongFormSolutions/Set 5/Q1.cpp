// IntArray Class

#include <iostream>

class IntArray {
private:
    int* data;
    int size; // current number of elements

public:
    // Constructor
    IntArray(int n) : size(n) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = 0; // Initialize to 0
        }
    }

    // Destructor
    ~IntArray() {
        delete[] data;
    }

    // Push back method - adds an element at the end
    void pushBack(int value) {
        // Create a new array with size+1
        int* newArr = new int[size + 1];

        // Copy old data
        for(int i = 0; i < size; i++) {
            newArr[i] = data[i];
        }

        // Add the new element
        newArr[size] = value;

        // Delete old array
        delete[] data;

        // Update data pointer and size
        data = newArr;
        size++;
    }

    int getSize() const {
        return size;
    }

    int getElement(int index) const {
        if(index >= 0 && index < size) {
            return data[index];
        }
        return -1; // error code
    }

    void setElement(int index, int value) {
        if(index >= 0 && index < size) {
            data[index] = value;
        }
    }
};

int main() {
    IntArray arr(3);
    arr.setElement(0, 10);
    arr.setElement(1, 20);
    arr.setElement(2, 30);

    arr.pushBack(40);

    std::cout << "Array elements: ";
    for(int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.getElement(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}