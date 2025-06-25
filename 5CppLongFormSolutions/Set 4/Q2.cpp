// Binary Search

#include <iostream>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if(left > right) {
        return -1; // base case: not found
    }
    int mid = (left + right) / 2;
    if(arr[mid] == target) {
        return mid;
    } else if(arr[mid] < target) {
        return binarySearchRecursive(arr, mid+1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid-1, target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;

    int result = binarySearchRecursive(arr, 0, n-1, target);
    if(result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}