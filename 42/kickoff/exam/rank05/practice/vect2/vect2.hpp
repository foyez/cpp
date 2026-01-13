#ifndef VECT2
#define VECT2

#include <iostream>

class vect2
{
private:
  int x;
  int y;

public:
  vect2();
  vect2(int x, int y);
  vect2(const vect2 &other);

  vect2 &operator=(const vect2 &other);

  // addition/subtraction/multiplication assignment operator
  vect2 &operator+=(const vect2 &other);
  vect2 &operator-=(const vect2 &other);
  vect2 &operator*=(int scalar);

  // increment operators
  vect2 &operator++();   // prefix increment
  vect2 operator++(int); // postfix increment

  // decrement operators
  vect2 &operator--();   // prefix decrement
  vect2 operator--(int); // postfix decrement

  // unary minus operator
  vect2 operator-() const;

  // comparision operators
  bool operator==(const vect2 &other) const;
  bool operator!=(const vect2 &other) const;

  // array subscript operator
  int &operator[](int index);
  const int &operator[](int index) const;
};

// binary arithmetic operators
vect2 operator+(const vect2 &a, const vect2 &b);
vect2 operator-(const vect2 &a, const vect2 &b);
vect2 operator*(const vect2 &v, int scalar);
vect2 operator*(int scalar, const vect2 &v);

std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif