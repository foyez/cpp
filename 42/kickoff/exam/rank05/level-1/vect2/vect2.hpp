#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
  int x;
  int y;

public:
  // constructor
  vect2();                   // default constructor
  vect2(int x, int y);       // parameterized constructor
  vect2(const vect2 &other); // copy constructor

  // assignment operator
  vect2 &operator=(const vect2 &other);

  // arithmetic operators (member functions)
  vect2 &operator+=(const vect2 &other);
  vect2 &operator-=(const vect2 &other);
  vect2 &operator*=(int scalar);

  // increment/decrement operators
  vect2 &operator++();   // prefix increment
  vect2 operator++(int); // postfix increment
  vect2 &operator--();   // prefix decrement
  vect2 operator--(int); // postfix decrement

  // unary minus operator
  vect2 operator-() const;

  // binary arithmetic operator (member functions)
  // vect2 operator+(const vect2 &other) const;

  // comparison operators
  bool operator==(const vect2 &other) const;
  bool operator!=(const vect2 &other) const;

  // array subscript operator
  int &operator[](int index); // non-const version
  const int &operator[](int index) const;
};

// binary arithmetic operators
vect2 operator+(const vect2 &a, const vect2 &b);
vect2 operator-(const vect2 &a, const vect2 &b);
vect2 operator*(const vect2 &v, int scalar);
vect2 operator*(int scalar, const vect2 &v);

// Stream Intersection Operator
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif