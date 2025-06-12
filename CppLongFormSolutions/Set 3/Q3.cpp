// Operator Overloading

#include <iostream>
using namespace std;

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
    cout << "Initial count: " << c.getCount() << endl;
    ++c; // Use overloaded ++
    cout << "After ++c: " << c.getCount() << endl;
    return 0;
}