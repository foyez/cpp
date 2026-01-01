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

  return (0);
}