#ifndef BIGINT
#define BIGINT

#include <iostream>

class bigint
{
private:
  std::string digits;

public:
  bigint();
  bigint(unsigned long long n);
  bigint(const std::string &str);
  bigint(const bigint &other); // copy constructor

  // assignment operator
  bigint &operator=(const bigint &other);

  // addition assignment operator
  bigint &operator+=(const bigint &ohter);

  // increment operator
  bigint &operator++();   // prefix increment
  bigint operator++(int); // posfix increment

  // comparison operators
  bool operator==(const bigint &other) const;
  bool operator!=(const bigint &other) const;
  bool operator>(const bigint &other) const;
  bool operator>=(const bigint &other) const;
  bool operator<(const bigint &other) const;
  bool operator<=(const bigint &other) const;

  // digit shift operators
  bigint &operator<<=(unsigned long long shift);
  bigint &operator<<=(const bigint &other);
  bigint operator<<(unsigned long long shift) const;
  bigint operator<<(const bigint &other) const;
  bigint &operator>>=(unsigned long long shift);
  bigint &operator>>=(const bigint &other);
  bigint operator>>(unsigned long long shift) const;
  bigint operator>>(const bigint &other) const;

  // addition operator
  bigint operator+(const bigint &other) const;

  const std::string &getDigits() const;

  void removeLeadingZeros();
};

std::ostream &operator<<(std::ostream &os, const bigint &num);

#endif