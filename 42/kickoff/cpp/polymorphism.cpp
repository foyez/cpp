// Polymorphism
// Polymorphism = one interface, many forms.
// A base class pointer/reference can point to objects of derived classes,
// and call the derived class’s overridden functions at runtime.

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// =========================
// STEP 0: Simple non-polymorphic version
// =========================
class Shape_NoVirtual {
public:
  void draw() const { cout << "Shape_NoVirtual::draw()\n"; }
};

class Circle_NoVirtual : public Shape_NoVirtual {
public:
  void draw() const { cout << "Circle_NoVirtual::draw()\n"; }
};

// =========================
// STEP 1: Add virtual to enable polymorphism
// =========================
class Shape {
public:
    // virtual draw -> allows derived overrides to be called through base pointers/references
    virtual void draw() const {
      cout << "Shape::draw()\n";
    }
};

class Circle : public Shape {
public:
  // override?
  // Because it gives the compiler the ability to verify:
  // Does this function exist in the base class?
  // Are the signatures identical?
  // Is the base function actually virtual?
  // Are you really overriding and not overloading/hiding?
  // Best practice:
  // Always use override for every overridden function. Always.
  // It makes code safer and easier to maintain.
  void draw() const override { cout << "Circle::draw()\n"; }
};

class Square : public Shape {
  public:
    void draw() const override { cout << "Square::draw()\n"; }
};

// =========================
// STEP 2: Make Shape abstract (pure virtual) and add more features
// =========================
class AbstractShape {
public:
    // pure virtual -> AbstractShape cannot be instantiated
    virtual void draw() const = 0;

    // non-pure virtual that derived classes may call if they want
    virtual string name() const { return "AbstractShape"; }

    // If you use inheritance with polymorphism (base pointer → derived object):
    //    -> The base class destructor must be virtual. 
    //    -> Otherwise, it will Only base destructor, NOT the derived destructor
    // virtual destructor (important when deleting derived via base pointer)
    virtual ~AbstractShape() = default;
};

class Triangle : public AbstractShape {
public:
  void draw() const override { cout << "Triangle::draw()\n"; }
  string name() const override { return "Triangle"; }
};

// =========================
// STEP 3: Demonstrate object slicing
// =========================
void demonstrate_slicing() {
  cout << "\n--- SLICING DEMO ---\n";
  Circle c;
  Shape s = c;                // object slicing: s is a pure Shape object
  c.draw();                   // Circle::draw()
  s.draw();                   // Shape::draw()  <-- Dog-eared part (no polymorphism)
}

// =========================
// STEP 4: Polymorphism with base pointer and reference
// =========================
void demonstrate_polymorphism_ptr_ref() {
  cout << "\n--- POINTER/REFERENCE POLYMORPHISM ---\n";
  Circle circle;
  Shape* p = &circle;         // pointer to base, actual object is Circle
  Shape& r = circle;          // reference to base, actual object is Circle

  p->draw();                  // Circle::draw()
  r.draw();                   // Circle::draw()
}

// =========================
// STEP 5: Why virtual destructor matters (bad example with raw pointers)
// =========================
class BaseBad {
public:
  BaseBad() { cout << "BaseBad constructed\n"; }
  ~BaseBad() { cout << "BaseBad destroyed\n"; } // NOT virtual
  virtual void draw() const { cout << "BaseBad::draw\n"; }
};

class DerivedBad : public BaseBad {
private:
  int* heapInt;
public:
  DerivedBad() : heapInt(new int(42)) { cout << "DerivedBad constructed\n"; }
  ~DerivedBad() { cout << "DerivedBad destroyed and freeing heapInt\n"; delete heapInt; }
  void draw() const override { cout << "DerivedBad::draw\n"; }
};

void demonstrate_bad_destructor() {
  cout << "\n--- BAD VIRTUAL-DESTRUCTOR DEMO (undefined behavior) ---\n";
  BaseBad* p = new DerivedBad();
  p->draw();
  delete p; // DerivedBad destructor is NOT called -> leak / UB
  cout << "(Above: DerivedBad destructor wasn't guaranteed to run because BaseBad::~BaseBad isn't virtual.)\n";
}

// =========================
// STEP 6: Correct virtual destructor and polymorphic container
// =========================
class BaseGood {
public:
  BaseGood() { cout << "BaseGood constructed\n"; }
  virtual ~BaseGood() { cout << "BaseGood destroyed\n"; } // virtual destructor
  virtual void draw() const = 0; // make base abstract
};

class DerivedGoodA : public BaseGood {
public:
  DerivedGoodA() { cout << "DerivedGoodA constructed\n"; }
  ~DerivedGoodA() override { cout << "DerivedGoodA destroyed\n"; }
  void draw() const override { cout << "DerivedGoodA::draw\n"; }
};

class DerivedGoodB : public BaseGood {
public:
  DerivedGoodB() { cout << "DerivedGoodB constructed\n"; }
  ~DerivedGoodB() override { cout << "DerivedGoodB destroyed\n"; }
  void draw() const override { cout << "DerivedGoodB::draw\n"; }
};

// function that accepts base pointer and demonstrates runtime dispatch
void render(const BaseGood& s) {
  cout << "[render] calling draw(): ";
  s.draw();
}

void demonstrate_polymorphic_container() {
  cout << "\n--- POLYMORPHIC CONTAINER (use smart pointers) ---\n";
  vector<unique_ptr<BaseGood>> shapes;
  shapes.emplace_back(make_unique<DerivedGoodA>());
  shapes.emplace_back(make_unique<DerivedGoodB>());

  cout << "Iterate and draw:\n";
  for (const auto& sp : shapes) {
      sp->draw();
  }

  // demonstrate passing by reference (no slicing, virtual dispatch works)
  render(*shapes[0]);
}

// Without polymorphism (ugly):
// void drawCircle(Circle c) {}
// void drawSquare(Square s) {}
// void drawTriangle(Triangle t) {}
// With polymorphism (clean):
void draw(Shape* s) {
    s->draw();
}
// draw(new Circle());
// draw(new Square());
// draw(new Triangle());

// Function Overloading = same function name, different parameter lists.
// Compiler decides which one to use at compile time (static polymorphism).
// Overloading Rules
// You can overload functions if they differ by:
// ✔ Number of parameters
// void f(int);
// void f(int, int);
// ✔ Types of parameters
// void f(double);
// void f(string);
// ✔ Order of parameters
// void f(int, double);
// void f(double, int);
// ❌ You CANNOT overload by return type alone
// int f();
// double f();  // ❌ error — same signature
// The compiler cannot distinguish them.
class Printer {
public:
  void print(int x) {
    cout << "Printing int: " << x << endl;
  }

  void print(double x) {
    cout << "Printing double: " << x << endl;
  }

  void print(const string& s) {
    cout << "Printing string: " << s << endl;
  }
};


// =========================
// STEP 7: Final demo showing all steps in sequence
// =========================
int main() {
  cout << "STEP 0: Non-polymorphic behaviour\n";
  {
    Shape_NoVirtual sn;
    Circle_NoVirtual cn;
    Shape_NoVirtual* p = &cn; // pointer to base but type is base; no virtual => base version called
    sn.draw();    // Shape_NoVirtual::draw()
    cn.draw();    // Circle_NoVirtual::draw()
    p->draw();    // Shape_NoVirtual::draw()  <-- no polymorphism without virtual
  }

  cout << "\nSTEP 1: Virtual functions enable polymorphism\n";
  {
    Shape s;
    Circle c;
    Shape* p = &c;
    s.draw();      // Shape::draw
    c.draw();      // Circle::draw
    p->draw();     // Circle::draw  <-- runtime dispatch
  }

  cout << "\nSTEP 2: Abstract base + override + virtual destructor\n";
  {
    Triangle t;
    t.draw();
    cout << "Triangle name(): " << t.name() << endl;
  }

  cout << "\n--- OVERLOADING ---\n";
  {
    Printer p;
    p.print(5);          // int version
    p.print(3.14);       // double version
    p.print("hello");    // string version
  }

  demonstrate_slicing();
  demonstrate_polymorphism_ptr_ref();

  // BAD destructor demo (shows why virtual destructor is needed)
  demonstrate_bad_destructor();

  // GOOD destructor + container demo
  demonstrate_polymorphic_container();

  cout << "\nAll demos finished. Note: smart pointers freed objects automatically.\n";
  return 0;
}
