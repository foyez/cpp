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

// If you don’t define copy constructor, C++ automatically provides a shallow copy constructor
// This default copy constructor performs a member-wise copy:
//      -> For built-in types (int, double, pointers), it copies the value.
//      -> For classes, it calls their copy constructors.
//      -> For pointers, it copies only the pointer address, not the data it points to.
// This is what we call a shallow copy.

int main() {
    {
        Point p1(3, 4);
        Point p2 = p1;  // copy constructor
        Point p3(p1);   // copy constructor

        p1.display();
        p2.display();
        p3.display();
    }
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
}
