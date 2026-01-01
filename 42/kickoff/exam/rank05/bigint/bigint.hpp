#ifndef BIGINT
#define BIGINT

#include <iostream>

class bigint
{
private:
  std::string digits;

public:
  // constructors
  bigint();                     // default constructor
  bigint(unsigned long long n); // unsigned long long parameterized constructor
  bigint(const bigint &other);  // copy constructor

  // getter for accessing digits
  const std::string &getDigits() const;
};

// Stream Intersection Operator
std::ostream &operator<<(std::ostream &os, const bigint &num);

#endif