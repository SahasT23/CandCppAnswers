// Bubble sort function template - advanced

#include <iostream>
#include <string>

template <typename T>
void bubbleSort(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while(swapped);
}

int main() {
    int arrInt[] = {5, 2, 9, 1, 5, 6};
    int sizeInt = sizeof(arrInt)/sizeof(arrInt[0]);

    bubbleSort(arrInt, sizeInt);
    std::cout << "Sorted int array: ";
    for(int i = 0; i < sizeInt; i++) {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;

    std::string arrStr[] = {"Charlie", "Alice", "Bob"};
    int sizeStr = sizeof(arrStr)/sizeof(arrStr[0]);

    bubbleSort(arrStr, sizeStr);
    std::cout << "Sorted string array: ";
    for(int i = 0; i < sizeStr; i++) {
        std::cout << arrStr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}