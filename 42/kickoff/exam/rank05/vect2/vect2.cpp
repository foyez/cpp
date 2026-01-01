#include "vect2.hpp"

// default constructor - initialize to (0, 0)
vect2::vect2() : x(0), y(0) {}

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