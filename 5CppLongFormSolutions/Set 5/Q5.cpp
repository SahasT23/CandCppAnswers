// Merge Sort class

#include <iostream>

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    double* L = new double[n1];
    double* R = new double[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

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
    int n;
    std::cout << "Enter number of floats: ";
    std::cin >> n;

    double* arr = new double[n];
    std::cout << "Enter " << n << " floating-point numbers:\n";
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    std::cout << "Sorted floats:\n";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}