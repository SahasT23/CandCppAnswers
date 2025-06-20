// Friend Function

#include <iostream>

class Beta; // Forward declaration

class Alpha {
private:
    int aVal;

public:
    Alpha(int val) : aVal(val) {}

    // Declare friend function
    friend void addAlphaBeta(const Alpha&, const Beta&);
};

class Beta {
private:
    int bVal;

public:
    Beta(int val) : bVal(val) {}

    // Declare friend function
    friend void addAlphaBeta(const Alpha&, const Beta&);
};

void addAlphaBeta(const Alpha& A, const Beta& B) {
    std::cout << "Sum of Alpha and Beta values: " << (A.aVal + B.bVal) << std::endl;
}

int main() {
    Alpha alphaObj(10);
    Beta betaObj(20);
    addAlphaBeta(alphaObj, betaObj);
    return 0;
}