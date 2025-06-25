// Smart pointer - extra

#include <iostream>
#include <memory> // for std::unique_ptr

int main() {
    // Using a raw pointer (not recommended in modern C++)
    {
        int* rawPtr = new int(10);
        std::cout << "Raw pointer value: " << *rawPtr << std::endl;
        delete rawPtr; // Must remember to delete
    }

    // Using std::unique_ptr
    {
        std::unique_ptr<int> smartPtr = std::make_unique<int>(20);
        std::cout << "Smart pointer value: " << *smartPtr << std::endl;
        // No need to call delete; it happens automatically
    }

    // Once the scope ends, the memory for the smart pointer is automatically freed

    return 0;
}