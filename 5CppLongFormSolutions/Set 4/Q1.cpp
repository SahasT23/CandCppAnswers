// Linear Search

#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the target to search: ";
    std::cin >> target;

    int result = linearSearch(arr, n, target);
    if(result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    delete[] arr;
    return 0;
}