#include <iostream>

// 1. Encapsulation
class BankAccount { 
private: // encapsulation: private member
    // to prevent direct access from outside the class
    int balance; // SOLUTION -- should be private for encapsulation -- SOLUTION

public: // Added public access specifier
    void deposit(int amount) { // method to modify balance
        balance += amount; // should be a member function
    }

    void display() { // method to display balance
        std::cout << "Balance: " << balance << std::endl; // should be a member function
    }
};

//=========================================================

// 2. Constructor & Destructor
class Sample { // constructor and destructor example
    int* data; // pointer to dynamically allocated memory
public: // constructor to allocate memory
    Sample(int value) { // constructor to initialize data
        data = new int(value); // SOLUTION -- allocated with new -- SOLUTION
    }

    ~Sample() { // destructor to free memory
        delete data;  // SOLUTION -- must free dynamically allocated memory -- SOLUTION
        data = nullptr;  // SOLUTION -- set pointer to nullptr to avoid dangling pointer -- SOLUTION
    }
};

//=========================================================

// 3. Method Overriding with Virtual
class Animal { // base class for polymorphism
public: // method to be overridden
    virtual void speak() { // SOLTUION -- added virtual for polymorphism -- SOLUTION
        // base class method
        std::cout << "Animal sound" << std::endl; // should be virtual for polymorphism
    }
};

class Dog : public Animal {  // derived class overriding base class method
public: // overriding speak method
    void speak() override { // override base class method
        std::cout << "Bark!" << std::endl; // should override base class method
    }
};

//=========================================================

// 4. Getters and Setters
class Student { // class with private member
    // encapsulation: private member
    // to prevent direct access from outside the class
private: // private member variable
    int age; // should be private for encapsulation
public:  // constructor to initialise age
    void setAge(int a) { // setter to modify age
        if (a > 0) // check for valid age
            age = a;  // should be a member function
    }

    int getAge() {  // getter to access age
        return age;
    }
};

int main() {
    Student s;
    s.setAge(20); // SOLUTION -- setter should be called like a function -- SOLUTION
    std::cout << s.getAge() << std::endl;
}

//=========================================================

// 5. Friend Class Functions
class B; // forward declaration of class B

class A { // class A with a friend function
    int value; // private member variable
public: 
    A() { value = 5; } 
    friend void show(const A&, const B&); // SOLUTION -- friend function declaration -- SOLUTION
};

class B { // class B with a friend function
    int data; // private member variable
public: 
    B() { data = 10; } // data member initialised in constructor
    friend void show(const A&, const B&); // friend function declaration
};

void show(const A& a, const B& b) { // friend function definition
    std::cout << a.value + b.data << std::endl; // should access private members of A and B
    // and print their sum
}

//=========================================================

// 6. Constructor Delegation
class Rectangle { // class with constructor delegation
    int width, height; // private member variables
public: // constructor to initialise width and height
    Rectangle(int w) : Rectangle(w, 1) {} // SOLUTION -- delegate to another constructor SOLUTION

    Rectangle(int w, int h) { // constructor to initialise width and height
        width = w; // should be a member function
        height = h;  // should be a member function
    }
};

//=========================================================

// 7. Polymorphism Fix
class Shape { // base class for polymorphism
public: // method to be overridden
    virtual void draw() {  // SOLUTION -- added virtual for polymorphism -- SOLUTION
        std::cout << "Drawing shape" << std::endl; // base class method
    }
};

class Circle : public Shape { // derived class overriding base class method
public: // overriding draw method
    void draw() override { // override base class method
        std::cout << "Drawing circle" << std::endl; // should override base class method
    }
};

//=========================================================

// 8. Dynamic Allocation
class Box { // class with dynamic memory allocation
    int* length; // pointer to dynamically allocated memory
public: 
    Box(int l) { // constructor to initialise length
        length = new int(l); // SOLUTION -- allocate before dereferencing SOLUTION
    }

    void display() { // method to display length
        std::cout << *length << std::endl; // should dereference pointer to display value
    }

    ~Box() { // destructor to free memory
        delete length; // must free dynamically allocated memory
    }
};

//=========================================================

// 9. Accessing Protected Members
class Base { // base class with protected member
protected: // protected member variable
    int val; // should be protected to allow access in derived classes
};

class Derived : private Base { // derived class inheriting from Base
    // private inheritance to restrict access to Base members
public: // constructor to initialise val
    void setVal(int v) { // method to set value of val
        val = v; // should be a member function
    }

    int getVal() {
        return val;
    }
};

int main() {
    Derived d;
    // d.val = 5; // ERROR: can't access private member from outside
    d.setVal(5);   // SOLUTION -- correct usage via public interface -- SOLUTION
    std::cout << d.getVal() << std::endl;
}

//=========================================================

// 10. Static Member Init
class Counter { // class with static member
    static int count; // static member variable to keep track of count
public: // static member function to initialise count
    Counter() { count++; } // constructor to increment count
    int getCount() { return count; } // method to get count
};

int Counter::count = 0; // SOLUTION -- definition of static member variable -- SOLUTION

//=========================================================

// 11. Friend Function Declaration
class X; // forward declaration of class X

void printX(const X&); // SOLUTION -- forward declaration of friend function -- SOLUTION

class X { // class with a friend function
    int value; // private member variable
    friend void printX(const X&); // friend function declaration
public: // constructor to initialise value
    X() { value = 10; } // constructor to initialise value
}; 

void printX(const X& x) { // friend function definition
    std::cout << x.value << std::endl; // should access private member of X and print out its value
}

//=========================================================

// 12. Multiple Inheritance
class A { // class A with a method
public: //  constructor to initialise A
    void print() { // method to print A
        std::cout << "A" << std::endl; // should print "A"
    }
};

class B { // class B with a method
    // encapsulation: private member
    // to prevent direct access from outside the class
public: // constructor to initialise B
    void print() { // method to print B
        std::cout << "B" << std::endl; // should print "B"
    }
};

class C : public A, public B { // class C inheriting from A and B
    // multiple inheritance: C inherits from both A and B
    // this can lead to ambiguity if not handled properly
    // when calling print() method, it is ambiguous which print() to call
    // because both A and B have a print() method
    // to resolve this ambiguity, we can specify which class's print() method to call
    // using scope resolution operator
    // C::A::print() or C::B::print()
public:
    void show() { // method to demonstrate multiple inheritance
        A::print(); // SOLUTION -- specify class to avoid ambiguity --SOLUTION
    }
};

//=========================================================

// 13. Abstract Class Use
class AbstractShape { // abstract class with a pure virtual function
    // encapsulation: private member
    // to prevent direct access from outside the class
public: // pure virtual function to make this class abstract
    virtual void draw() = 0; // pure virtual function
    // this makes AbstractShape an abstract class
    // and it cannot be instantiated directly
    // derived classes must implement this function
};

class Triangle : public AbstractShape { // derived class implementing the abstract class
    // encapsulation: private member
    // to prevent direct access from outside the class
public: // overriding the pure virtual function
    void draw() override { // override the pure virtual function
        std::cout << "Triangle" << std::endl; // should override the pure virtual function
    }
};

int main() {
    Triangle t;  // SOLUTION -- instantiate derived class instead -- SOLUTION
    t.draw();
}

//=========================================================

// 14. Copy Constructor
class Item { // class with a copy constructor
    int value; // private member variable
public: // constructor to initialise value
    Item(int v) { value = v; } // SOLUTION -- Copy constructor to initialise value -- SOLUTION

    Item(const Item& other) { // added copy constructor
        value = other.value; // copy value from other
    }
};

int main() {
    Item a(5);
    Item b = a; // uses copy constructor
}

//=========================================================

// 15. Default Constructor for Initialiser List Class
class Point { // class with a default constructor
    int x, y; // private member variables
public: // constructor to initialise x and y
    // encapsulation: private member
    // to prevent direct access from outside the class
    Point() : x(0), y(0) {} // SOLUTION -- added and defined default constructor -- SOLUTION

    Point(int a, int b) : x(a), y(b) { } // constructor to initialise x and y with parameters

    void print() { // method to print x and y
        std::cout << x << "," << y << std::endl; // should print x and y
    }
};

int main() {
    Point p;
    p.print();
}

//========================================================
