// Selection Sort for students

#include <iostream>

void selectionSort(int* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    std::cout << "How many student IDs?: ";
    std::cin >> n;

    int* ids = new int[n];
    std::cout << "Enter " << n << " student IDs:\n";
    for(int i = 0; i < n; i++) {
        std::cin >> ids[i];
    }

    selectionSort(ids, n);

    std::cout << "Sorted IDs:\n";
    for(int i = 0; i < n; i++) {
        std::cout << ids[i] << " ";
    }
    std::cout << std::endl;

    delete[] ids;
    return 0;
}