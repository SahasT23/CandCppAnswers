// Selection Sort

#include <iostream>
using namespace std;

void selectionSortDescending(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[maxIndex]) { // search for the maximum
                maxIndex = j;
            }
        }
        // Swap
        if(maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSortDescending(arr, n);

    cout << "Array sorted in descending order: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}