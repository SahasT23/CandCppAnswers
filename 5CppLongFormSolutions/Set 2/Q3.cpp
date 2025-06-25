// 2D dynamic array implementation

#include <iostream>

int main() {
    int rows = 3, cols = 4;

    // Allocate memory for 2D array
    int** array2D = new int*[rows];
    for(int i = 0; i < rows; i++) {
        array2D[i] = new int[cols];
    }

    // Fill array
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            array2D[r][c] = r + c;
        }
    }

    // Print array
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            std::cout << array2D[r][c] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    for(int i = 0; i < rows; i++) {
        delete[] array2D[i];
    }
    delete[] array2D;
    array2D = nullptr;

    return 0;
}