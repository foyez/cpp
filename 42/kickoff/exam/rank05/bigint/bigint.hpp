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
  // bigint(const std::string &str); // string parameterized constructor
  bigint(const bigint &other); // copy constructor

  // assignment operator
  // bigint &operator=(const bigint &other);

  // addition assignment operator
  bigint &operator+=(const bigint &other);

  // addition operator
  bigint operator+(const bigint &other) const;

  // increment operators
  bigint &operator++();   // prefix increment
  bigint operator++(int); // postfix increment

  // comparison operators
  bool operator==(const bigint &other) const;
  bool operator!=(const bigint &other) const;
  bool operator<(const bigint &other) const;
  bool operator<=(const bigint &other) const;
  bool operator>(const bigint &other) const;
  bool operator>=(const bigint &other) const;

  // digit shift operators
  bigint &operator<<=(unsigned long long shift);
  bigint &operator<<=(const bigint &shift);
  bigint operator<<(unsigned long long shift) const;
  bigint operator<<(const bigint &shift) const;

  bigint &operator>>=(unsigned long long shift);
  bigint &operator>>=(const bigint &shift);
  bigint operator>>(unsigned long long shift) const;
  bigint operator>>(const bigint &shift) const;

  // getter for accessing digits
  const std::string &getDigits() const;

  // remove leading zeros from the string
  void removeLeadingZeros();
};

// Stream Intersection Operator
std::ostream &operator<<(std::ostream &os, const bigint &num);

#endif