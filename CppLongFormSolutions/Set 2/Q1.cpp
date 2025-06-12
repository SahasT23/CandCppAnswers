// Doesn't run, just the function

// createArray function
int* createArray(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int size = 5;
    int* myArray = createArray(size);

    // Print the array
    for(int i = 0; i < size; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Free memory
    delete[] myArray;
    myArray = nullptr;

    return 0;
}