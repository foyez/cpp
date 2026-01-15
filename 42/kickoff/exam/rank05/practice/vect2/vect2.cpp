#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2 &other) : x(other.x), y(other.y) {}

vect2 &vect2::operator=(const vect2 &other)
{
  if (this != &other)
  {
    x = other.x;
    y = other.y;
  }
  return *this;
}

// addition assignment operator
vect2 &vect2::operator+=(const vect2 &other)
{
  x += other.x;
  y += other.y;
  return *this;
}

// subtraction assignment operator
vect2 &vect2::operator-=(const vect2 &other)
{
  x -= other.x;
  y -= other.y;
  return *this;
}

// multiplication assignment operator
vect2 &vect2::operator*=(int scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

vect2 &vect2::operator++()
{
  ++x;
  ++y;
  return *this;
}

vect2 vect2::operator++(int)
{
  vect2 tmp(*this);
  ++(*this);
  return tmp;
}

vect2 &vect2::operator--()
{
  --x;
  --y;
  return *this;
}

vect2 vect2::operator--(int)
{
  vect2 tmp(*this);
  --(*this);
  return tmp;
}

// unary minus operator
vect2 vect2::operator-() const
{
  return vect2(-x, -y);
}

// binary arithmetic operators
vect2 operator+(const vect2 &a, const vect2 &b)
{
  return vect2(a[0] + b[0], a[1] + b[1]);
}

vect2 operator-(const vect2 &a, const vect2 &b)
{
  return vect2(a[0] - b[0], a[1] - b[1]);
}

vect2 operator*(const vect2 &v, int scalar)
{
  return vect2(v[0] * scalar, v[1] * scalar);
}

vect2 operator*(int scalar, const vect2 &v)
{
  return vect2(v[0] * scalar, v[1] * scalar);
}

// comparision operators
bool vect2::operator==(const vect2 &other) const
{
  return (x == other.x) && (y == other.y);
}

bool vect2::operator!=(const vect2 &other) const
{
  return !(*this == other);
}

// array subscript operators
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

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
  os << "{" << v[0] << ", " << v[1] << "}";
  return os;
}