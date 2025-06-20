// bubble sort

#include <iostream>
#include <string>

void bubbleSortStrings(std::string arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                // Swap
                std::string temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while(swapped);
}

int main() {
    std::string arr[] = {"Charlie", "Alice", "Bob", "Dave"};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSortStrings(arr, n);

    std::cout << "Sorted strings (Bubble Sort): ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}