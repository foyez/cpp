#include "bigint.hpp"
#include <iostream>

int main(void)
{
  const bigint a(42);
  bigint b(21), c, d(1337), e(d);

  // base test
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;

  std::cout << "a + b = " << a + b << std::endl;
  std::cout << "a + c = " << a + c << std::endl;
  std::cout << "(c += a) = " << (c += a) << std::endl;

  std::cout << "b = " << b << std::endl;
  std::cout << "++b = " << ++b << std::endl;
  std::cout << "b++ = " << b++ << std::endl;

  std::cout << "(d < a) = " << (d < a) << std::endl;   // (d < a) = 0
  std::cout << "(d > a) = " << (d > a) << std::endl;   // (d > a) = 1
  std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
  std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
  std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
  std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

  return (0);
}