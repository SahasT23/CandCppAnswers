// Circle Class

#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r = 0.0) : radius(r) {}

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle c1;         // Default constructor
    c1.setRadius(5.0); // Set radius
    cout << "Area of circle: " << c1.getArea() << endl;
    return 0;
}