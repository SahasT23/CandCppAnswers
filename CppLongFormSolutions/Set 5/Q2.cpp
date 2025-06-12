// Searchable Array Class

#include <iostream>

class IntArray {
protected:
    int* data;
    int size;
public:
    IntArray(int n) : size(n) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    virtual ~IntArray() {
        delete[] data;
    }

    int getSize() const { return size; }

    void setElement(int index, int value) {
        if(index >= 0 && index < size) {
            data[index] = value;
        }
    }

    int getElement(int index) const {
        if(index >= 0 && index < size) {
            return data[index];
        }
        return -1;
    }
};

class SearchableArray : public IntArray {
public:
    SearchableArray(int n) : IntArray(n) {}

    // Binary search
    int binarySearch(int target) const {
        int left = 0;
        int right = size - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(data[mid] == target) {
                return mid;
            } else if(data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    SearchableArray sArr(5);
    // Suppose it is already sorted
    sArr.setElement(0, 2);
    sArr.setElement(1, 4);
    sArr.setElement(2, 6);
    sArr.setElement(3, 8);
    sArr.setElement(4, 10);

    int index = sArr.binarySearch(8);
    if(index != -1) {
        std::cout << "Found at index: " << index << std::endl;
    } else {
        std::cout << "Not found.\n";
    }

    return 0;
}