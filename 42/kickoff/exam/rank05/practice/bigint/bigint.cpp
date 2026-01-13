#include "bigint.hpp"

void bigint::removeLeadingZeros()
{
  size_t pos = 0;

  while (pos < digits.size() - 1 && digits[pos] == '0')
    pos++;

  if (pos > 0)
    digits = digits.substr(pos);
}

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long long n)
{
  if (n == 0)
    digits = "0";
  else
  {
    digits = "";
    while (n > 0)
    {
      digits = char('0' + (n % 10)) + digits;
      n /= 10;
    }
  }
}

bigint::bigint(const std::string &str)
{
  if (str.empty())
    digits = "0";
  else
  {
    digits = str;
    removeLeadingZeros();
  }
}

bigint::bigint(const bigint &other) : bigint(other.digits) {}

bigint &bigint::operator=(const bigint &other)
{
  if (this != &other)
    digits = other.digits;
  return *this;
}

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
    res = char('0' + (sum % 10)) + res;
  }

  digits = res;
  removeLeadingZeros();

  return *this;
}

// addition operator
bigint bigint::operator+(const bigint &other) const
{
  bigint res(*this);
  res += other;
  return res;
}

// prefix increment
bigint &bigint::operator++()
{
  *this += bigint(1);
  return *this;
}

// postfix increment
bigint bigint::operator++(int)
{
  bigint tmp(*this);
  // *this += bigint(1);
  ++(*this);
  return tmp;
}

// comparison operators
bool bigint::operator==(const bigint &other) const
{
  return digits == other.digits;
}

bool bigint::operator!=(const bigint &other) const
{
  return !(*this == other);
}

bool bigint::operator<(const bigint &other) const
{
  if (digits.size() != other.digits.size())
    return digits.size() < other.digits.size();

  return digits < other.digits;
}

bool bigint::operator<=(const bigint &other) const
{
  return (*this < other) || (*this == other);
}

bool bigint::operator>(const bigint &other) const
{
  return !(*this <= other);
}

bool bigint::operator>=(const bigint &other) const
{
  return !(*this < other);
}

// digit shift operators
// left shift assignment (digit shift left - multiply by 10^shift)
bigint &bigint::operator<<=(unsigned long long shift)
{
  if (shift == 0)
    return *this;

  if (digits == "0")
    return *this;

  // append zero to the right
  for (unsigned long long i = 0; i < shift; i++)
    digits += '0';

  return *this;
}

bigint &bigint::operator<<=(const bigint &other)
{
  unsigned long long shiftAmount = 0;

  for (size_t i = 0; i < other.digits.size(); i++)
    shiftAmount = shiftAmount * 10 + (other.digits[i] - '0');

  return *this <<= shiftAmount;
}

bigint bigint::operator<<(unsigned long long shift) const
{
  bigint res(*this);
  res <<= shift;
  return res;
}

bigint bigint::operator<<(const bigint &other) const
{
  bigint res(*this);
  res <<= other;
  return res;
}

// right shift assignment (digit shift right - divide by 10^shift)
bigint &bigint::operator>>=(unsigned long long shift)
{
  if (shift == 0)
    return *this;

  if (shift >= digits.size())
  {
    digits = "0";
    return *this;
  }

  // remove shift digits from the right
  digits = digits.substr(0, digits.size() - shift);

  if (digits.empty())
    digits = "0";

  removeLeadingZeros();
  return *this;
}

bigint &bigint::operator>>=(const bigint &other)
{
  unsigned long long shiftAmount = 0;

  for (size_t i = 0; i < other.digits.size(); i++)
    shiftAmount = shiftAmount * 10 + (other.digits[i] - '0');

  return *this >>= shiftAmount;
}

bigint bigint::operator>>(unsigned long long shift) const
{
  bigint res(*this);
  res >>= shift;
  return res;
}

bigint bigint::operator>>(const bigint &other) const
{
  bigint res(*this);
  res >>= other;
  return res;
}

const std::string &bigint::getDigits() const
{
  return digits;
}

std::ostream &operator<<(std::ostream &os, const bigint &num)
{
  os << num.getDigits();
  return os;
}