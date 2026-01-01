#include "vect2.hpp"

// default constructor - initialize to (0, 0)
vect2::vect2() : x(0), y(0) {}

// parameterized constructor
vect2::vect2(int x, int y) : x(x), y(y) {}

// copy constructor
vect2::vect2(const vect2 &other) : x(other.x), y(other.y) {}

// assignment operator
vect2 &vect2::operator=(const vect2 &other)
{
  if (this != &other)
  {
    x = other.x;
    y = other.y;
  }
  return *this;
}

int &vect2::operator[](int index)
{
  if (index == 0)
    return x;
  return y;
}

const int &vect2::operator[](int index) const
{
  if (index == 0)
    return x;
  return y;
}

// prefix increment (++v)
vect2 &vect2::operator++()
{
  ++x;
  ++y;
  return *this;
}

// postfix increment (v++)
vect2 vect2::operator++(int)
{
  vect2 tmp(*this); // save current state
  ++(*this);        // use prefix increment
  return tmp;       // return old state
}

// prefix decrement (--v)
vect2 &vect2::operator--()
{
  --x;
  --y;
  return *this;
}

// postfix decrement (v--)
vect2 vect2::operator--(int)
{
  vect2 tmp(*this); // save current state
  --(*this);        // use prefix decrement
  return tmp;       // return old state
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
  os << "{" << v[0] << ", " << v[1] << "}";
  return os;
}