// bubble sort

#include <iostream>
#include <string>
using namespace std;

void bubbleSortStrings(string arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                // Swap
                string temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while(swapped);
}

int main() {
    string arr[] = {"Charlie", "Alice", "Bob", "Dave"};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSortStrings(arr, n);

    cout << "Sorted strings (Bubble Sort): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}