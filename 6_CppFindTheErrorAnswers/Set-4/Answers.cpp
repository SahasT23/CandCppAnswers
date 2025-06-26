// Q1

//for (int i = 0; i <= n; i++) goes out of bounds. Should be i < n

// Searches for `key` in array `arr` of size `n`.
// Returns index if found, else returns -1.
int linearSearch(int arr[], int n, int key) {
    // Loop from index 0 to n-1. Original mistake was using i <= n (out of bounds).
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) // Check current element
            return i;      // Return index if found
    }
    return -1; // Return -1 if not found
}


//==========================================================

// Q2

// if (arr[mid] = key) is assignment instead of comparison. Should be ==

// Iteratively searches for `key` in sorted array `arr` between `left` and `right`.
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;

        // Mistake was '=' instead of '=='
        if (arr[mid] == key)
            return mid;

        // Eliminate half of the array based on comparison
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

//==========================================================

// Q3

// Inner loop ran until j < n, causing out-of-bounds read on arr[j-1].
// Didn't reduce comparison range in each outer pass.

// Sorts array `arr` of length `n` in ascending order using bubble sort.
void bubbleSort(int arr[], int n) {
    // Outer loop for n-1 passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop avoids redundant comparisons
        for (int j = 1; j < n - i; j++) {
            // Compare adjacent elements
            if (arr[j] < arr[j - 1]) {
                // Manual swap (avoid std::swap)
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

//==========================================================

// Q4

// Values were assigned during swap instead of being exchanged. 
// arr[i] = arr[min]; arr[min] = arr[i]; does not swap correctly.

// Sorts array `arr` of size `n` in ascending order using selection sort.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume first unsorted element is the minimum

        // Find the actual minimum in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Only swap if a smaller element is found
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//==========================================================

// Q5

// Called mergeSort(arr, mid, high) — incorrect: mid overlaps subarrays. Should be [mid + 1]
// Assumes presence of valid merge() implementation.

// Splits array `arr` from index `low` to `high`, recursively sorts both halves
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Mistake: Called mergeSort(arr, mid, high) — should use mid + 1
        mergeSort(arr, low, mid);      // Sort left half
        mergeSort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);    // Merge both halves (function implementation assumed)
    }
}

//==========================================================

// Q6

// Copy-back loop wrote arr[l] = temp[l], incorrectly indexing from l = left.
// Used variable-length array int temp[], which is not standard C++. 
// Replaced with heap-allocated arrays for portability and clarity.

// Merges two sorted subarrays of `arr[]`:
// First subarray: arr[left ... mid]
// Second subarray: arr[mid+1 ... right]

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // size of left subarray
    int n2 = right - mid;      // size of right subarray

    // Dynamically allocate space for temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temporary arrays back into arr[left ... right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];

    // Clean up
    delete[] L;
    delete[] R;
}

//==========================================================

// Q7

// The outer loop went to i < n, but only n - 1 passes are needed.
// No early termination if already sorted (fixed by checking swapped flag).

// Bubble Sort with early exit optimization
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // Compare adjacent elements and swap if needed
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Manual swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!swapped)
            break;
    }
}

//==========================================================

// Q8

// Missing return value on failure — return; in a non-void function. Should be return -1.

// Performs linear search on string array `arr[]`
int linearSearch(std::string arr[], int n, std::string key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) // Compare strings
            return i;      // Found at index i
    }
    return -1; // Not found — must return an int
}

//==========================================================

// Q9

// Final return for the left-side recursive call was missing. 
// Without it, caller doesn't receive the result.

// Recursively searches for `key` using binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1; // Base case: not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid; // Key found

    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key); // Right half

    else
        return binarySearch(arr, low, mid - 1, key); // Left half — this return was missing
};

//==========================================================

// Q10

// Incorrect use of swap(arr[i], arr[j]) inside inner loop. 
// Should be comparing and swapping arr[j] and arr[j+1].
// Index maths error.

// Sorts the array in descending order using bubble sort
void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if current is less than next — for descending order
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//==========================================================