// Inheritcance question

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a triangle." << endl;
    }
};

int main() {
    Shape* shapePtr;
    Rectangle rect;
    Triangle tri;

    shapePtr = &rect;
    shapePtr->draw(); // Calls Rectangle's draw()

    shapePtr = &tri;
    shapePtr->draw(); // Calls Triangle's draw()

    return 0;
}