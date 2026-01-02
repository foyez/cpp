#include "bigint.hpp"

// remove leading zeros from the string
void bigint::removeLeadingZeros()
{
  size_t pos = 0;
  while (pos < digits.size() - 1 && digits[pos] == '0')
  {
    pos++;
  }
  if (pos > 0)
  {
    digits = digits.substr(pos);
  }
}

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

// copy constructor
bigint::bigint(const bigint &other) : digits(other.digits) {}

// assignment operator
// bigint &bigint::operator=(const bigint &other)
// {
//   if (this != &other)
//   {
//     digits = other.digits;
//   }
//   return *this;
// }

// addition assignment operator
bigint &bigint::operator+=(const bigint &other)
{
  std::string res = "";
  int carry = 0;

  // start from the rightmost digit
  int i = digits.size() - 1;
  int j = other.digits.size() - 1;

  while (i >= 0 || j >= 0 || carry)
  {
    int sum = carry;

    if (i >= 0)
    {
      sum += (digits[i] - '0');
      i--;
    }

    if (j >= 0)
    {
      sum += (other.digits[j] - '0');
      j--;
    }

    carry = sum / 10;
    res = char('0' + (sum % 10)) + res; // prepend digit
  }

  digits = res;
  removeLeadingZeros();
  return *this;
}

// addition operator
bigint bigint::operator+(const bigint &other) const
{
  bigint result(*this); // use copy constructor
  result += other;      // use addition assignment operator
  return result;
}

// prefix increment (++a)
bigint &bigint::operator++()
{
  *this += bigint(1); // use parameterized constructor and addition assignment operator
  return *this;
}

// postfix increment (a++)
bigint bigint::operator++(int)
{
  bigint tmp(*this); // save current state
  ++(*this);         // use prefix increment
  return tmp;        // return old state
}

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
