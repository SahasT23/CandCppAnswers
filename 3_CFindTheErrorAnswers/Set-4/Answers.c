// Q1: Linear Search - off-by-one in loop condition
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) { // fixed from i <= n
        if (arr[i] == key)
            return i;
    }
    return -1;
}

//================================================

// Q2: Binary Search - assignment instead of comparison
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) // fixed '=' to '=='
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//================================================

// Q3: Selection Sort - incorrect swapping
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp; // fixed improper swap logic
        }
    }
}

//================================================

// Q4: Bubble Sort - inner loop bounds incorrect
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) { // fixed range to include comparison with j - 1
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

//================================================

// Q5: Merge - incorrect size calculations for temporary arrays
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // fixed n1 from m - l
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

//================================================

// Q6: Merge Sort - missing closing brace
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    } // fixed missing closing brace
}

//================================================

// Q7: Binary Search - base case condition reversed
int binarySearch(int arr[], int l, int r, int key) {
    if (l > r) // fixed l >= r to l > r
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binarySearch(arr, l, mid - 1, key);
    return binarySearch(arr, mid + 1, r, key);
}

//================================================

// Q8: Linear Search - incomplete loop range
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) { // fixed n - 1 to n
        if (arr[i] == target)
            return i;
    }
    return -1;
}

//================================================

// Q9: Selection Sort - incorrect swap overwrites value
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp; // fixed swap logic
        }
    }
}

//================================================

// Q10: Bubble Sort - redundant comparisons in inner loop
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // fixed outer loop to n - 1
        for (int j = 0; j < n - i - 1; j++) { // fixed inner loop range
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
