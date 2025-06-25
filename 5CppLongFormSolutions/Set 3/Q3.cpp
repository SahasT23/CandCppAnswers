// Operator Overloading

#include <iostream>


class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    // Overload prefix ++
    Counter& operator++() {
        ++count;   // increment
        return *this; // return the updated object
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c(5);
    std::cout << "Initial count: " << c.getCount() << std::endl;
    ++c; // Use overloaded ++
    std::cout << "After ++c: " << c.getCount() << std::endl;
    return 0;
}