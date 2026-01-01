#include "bigint.hpp"

bigint::bigint() : digits("0") {}

// constructor from unsigned long long
bigint::bigint(unsigned long long n)
{
  if (n == 0)
    digits = "0";
  else
  {
    digits = "";
    while (n > 0)
    {
      digits = char('0' + (n % 10)) + digits; // convert to ascii & prepend digit
      n /= 10;
    }
  }
}

bigint::bigint(const bigint &other) : digits(other.digits) {}

const std::string &bigint::getDigits() const
{
  return digits;
}

// stream intersection operator
std::ostream &operator<<(std::ostream &os, const bigint &num)
{
  os << num.getDigits();
  return os;
}
