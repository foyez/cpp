#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
    int *data;
public:
    // Constructor
    Point(int a, int b) {
        x = a;
        y = b;
        cout << "Constructor called" << endl;
    }

    ~Point() {
        cout << "Destructor called" << endl;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

class Point2 {
private:
    int x, y;
    int *data;
public:
    // Constructor
    Point2(int a, int b) {
        x = a;
        y = b;
        
        data = new int(a);
        cout << "Constructor: allocated data at " << data
             << " with value " << *data << endl;
    }

    ~Point2() {
        cout << "Destructor: deleting data at " << data << endl;
        delete data;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "data = " << *data << " (address = " << data << ")" << endl;
    }
};

class Point3 {
private:
    int x, y;
    int *data;
public:
    // Constructor
    Point3(int a, int b) {
        x = a;
        y = b;
        
        data = new int(a);
        cout << "Constructor: allocated data at " << data
             << " with value " << *data << endl;
    }

    // Copy constructor (deep copy)
    Point3(const Point3& other) {
        x = other.x;
        y = other.y;
        data = new int(*other.data); // allocate new memory + copy
        cout << "Copy constructor called\n";
    }

    ~Point3() {
        cout << "Destructor: deleting data at " << data << endl;
        delete data;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "data = " << *data << " (address = " << data << ")" << endl;
    }
};

class Point4 {
private:
    int x, y;
    int *data;
public:
    Point4(int value=0) {
        x = 0;
        y = 0;
        data = new int(value);
        cout << "Constructor: allocated data at " << data
             << " with value " << *data << endl;
    }

    // Constructor
    Point4(int a, int b) {
        x = a;
        y = b;
        
        data = new int(a);
        cout << "Constructor: allocated data at " << data
             << " with value " << *data << endl;
    }

    // Copy constructor (deep copy)
    Point4(const Point4& other) {
        x = other.x;
        y = other.y;
        data = new int(*other.data); // allocate new memory + copy
        cout << "Copy constructor called\n";
    }

    // Copy Assignment Operator (deep copy)
    Point4& operator=(const Point4& other) {
        cout << "Copy Assignment Operator\n";

        // Avoid self-assignment (a = a)
        if (this != &other) {
            delete data;                    // free old memory
            data = new int(*other.data);    // copy new memory
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    ~Point4() {
        cout << "Destructor: deleting data at " << data << endl;
        delete data;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "data = " << *data << " (address = " << data << ")" << endl;
    }
};

class Encapsulation {
private:
    int age;        // hidden from outside
    string name;    // hidden from outside

public:
    // Setter functions (write access)
    void setAge(int a) {
        if (a >= 0) age = a;
    }

    void setName(string n) {
        name = n;
    }

    // Getter functions (read access)
    int getAge() const {
        return age;
    }

    string getName() const {
        return name;
    }
};

// Inheritance
// Base class
class Animal {
protected:
    int age;
public:
    Animal() {
        age = 10;
    }
    ~Animal() {
        cout << "Animal destructor\n";
    }

    void eat() {
        cout << "Eating...\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    ~Dog() {
        cout << "Dog destructor\n";
    }

    void bark() {
        cout << age << " years old dog is " << "barking...\n";
    }
};

// If you don’t define copy constructor, C++ automatically provides a shallow copy constructor
// This default copy constructor performs a member-wise copy:
//      -> For built-in types (int, double, pointers), it copies the value.
//      -> For classes, it calls their copy constructors.
//      -> For pointers, it copies only the pointer address, not the data it points to.
// This is what we call a shallow copy.

// DESTRUCTOR
// A destructor is a special member function that is automatically called
// when an object goes out of scope or is deleted.
// Rules:
//      -> No return type
//      -> No parameters
//      -> Only one destructor per class
//      -> Called automatically

// Encapsulation
// Encapsulation means bundling data and functions together inside a class, and controlling access to them.
// You hide the internal details and expose only what should be visible.
// It protects your data from:
//      -> accidental modification
//      -> invalid modification
//      -> direct access from outside the class

// Inheritance
// Inheritance allows one class (child/derived class) to reuse and extend another class (parent/base class).
// It lets you:
//      -> Avoid repeating code
//      -> Build hierarchical relationships
//      -> Add new behavior to existing classes
// Destructor Behavior in Inheritance
// When a derived object is destroyed:
//      -> Derived class destructor runs first
//      -> Then Base class destructor runs
// This order is always:
// Derived → Base
// This ensures that:
//      -> The derived class cleans up its own resources first
//      -> Then the base class cleans up its part
// When constructing → base first, then derived
// When destructing → derived first, then base

int main() {
    // {
    //     Point p1(3, 4);
    //     Point p2 = p1;  // copy constructor
    //     Point p3(p1);   // copy constructor

    //     p1.display();
    //     p2.display();
    //     p3.display();
    // }
    // {
    //     Point2 p1(3, 4);
    //     Point2 p2 = p1;

    //     p1.display();
    //     p2.display();
    // }
    // {
    //     Point3 p1(3, 4);
    //     Point3 p2 = p1;

    //     p1.display();
    //     p2.display();
    // }
    // {
    //     Point4 p1(3, 4);
    //     Point4 p2 = p1; // copy constructor
    //     Point4 p3;
    //     p3 = p1;    // copy assignment operator

    //     p1.display();
    //     p2.display();
    //     p3.display();
    // }
    // {
    //     Encapsulation p;

    //     // Direct access → ❌ NOT allowed
    //     // p.age = 25;  // ERROR

    //     // Must use public functions → ✔ allowed
    //     p.setAge(25);
    //     p.setName("Alice");

    //     cout << p.getName() << " is " << p.getAge() << " years old\n";
    // }
    {
        Dog d;

        d.eat();   // inherited from Animal
        d.bark();  // Dog's own function
    }
}
