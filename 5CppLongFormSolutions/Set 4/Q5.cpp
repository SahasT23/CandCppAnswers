// Merge Sort

#include <iostream>
#include <algorithm> // for std::sort (comparison)

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double* L = new double[n1];
    double* R = new double[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(double arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    double arr[] = {3.14, 2.72, 1.41, 1.73, 2.18};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Copy array for comparison
    double arrCopy[n];
    for(int i = 0; i < n; i++) {
        arrCopy[i] = arr[i];
    }

    // Sort using Merge Sort
    mergeSort(arr, 0, n - 1);

    // Sort using std::sort for comparison
    std::sort(arrCopy, arrCopy + n);

    std::cout << "Merge-Sorted array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "std::sort array:    ";
    for(int i = 0; i < n; i++) {
        std::cout << arrCopy[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}