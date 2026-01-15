#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

class bigint
{
private:
  std::string digits;

public:
  // constructors
  bigint();                     // default constructor
  bigint(unsigned long long n); // parameterized constructor
  bigint(const std::string &str);
  bigint(const bigint &other); // copy constructor

  // assignment constructor
  bigint &operator=(const bigint &other);

  // addition assignment operator
  bigint &operator+=(const bigint &other);

  // addition operator
  bigint operator+(const bigint &other) const;

  // increment operators
  bigint &operator++();   // prefix increment
  bigint operator++(int); // postfix increment

  // comparision operators
  bool operator==(const bigint &other) const;
  bool operator!=(const bigint &other) const;
  bool operator<(const bigint &other) const;
  bool operator<=(const bigint &other) const;
  bool operator>(const bigint &other) const;
  bool operator>=(const bigint &other) const;

  // digit shift operator
  bigint &operator<<=(unsigned long long shift);
  bigint &operator<<=(const bigint &shift);
  bigint operator<<(unsigned long long shift) const;
  bigint operator<<(const bigint &shift) const;

  bigint &operator>>=(unsigned long long shift);
  bigint &operator>>=(const bigint &shift);
  bigint operator>>(unsigned long long shift) const;
  bigint operator>>(const bigint &shift) const;

  const std::string &getDigits() const;

  void removeLeadingZeros();
};

std::ostream &operator<<(std::ostream &os, const bigint &num);

#endif