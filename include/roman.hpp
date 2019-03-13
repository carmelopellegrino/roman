#ifndef ROMAN_HPP
#define ROMAN_HPP

#include <ostream>
#include <stdexcept>

namespace format {

class roman
{
  unsigned int number;

 public:

  explicit
  roman(unsigned int i)
  : number(i)
  {
    if (number == 0) {
      throw std::runtime_error("cannot represent zero");
    }

    if (number > 3999) {
      throw std::runtime_error("cannot represent a number >= 4000");
    }
  }

  friend
  std::ostream& operator <<(std::ostream& stream, roman const& number);
};

inline
std::ostream& operator <<(std::ostream& stream, roman const& number)
{
  auto const mil = number.number / 1000;
  auto const cen = (number.number - mil * 1000) / 100;
  auto const dec = (number.number - mil * 1000 - cen * 100) / 10;
  auto const uni = number.number % 10;

  for (auto i = 0; i != mil; ++i) {
    stream << 'M';
  }

  if (cen <= 3) {
    for (auto i = 0; i != cen; ++i) {
      stream << 'C';
    }
  } else if (cen == 4) {
    stream << "CD";
  } else if (cen < 9) {
    stream << 'D';
    for (auto i = 5; i != cen; ++i) {
      stream << 'C';
    }
  } else {
    stream << "CM";
  }

  if (dec <= 3) {
    for (auto i = 0; i != dec; ++i) {
      stream << 'X';
    }
  } else if (dec == 4) {
    stream << "XL";
  } else if (dec < 9) {
    stream << 'L';
    for (auto i = 5; i != dec; ++i) {
      stream << 'X';
    }
  } else {
    stream << "XC";
  }

  if (uni <= 3) {
    for (auto i = 0; i != uni; ++i) {
      stream << 'I';
    }
  } else if (uni == 4) {
    stream << "IV";
  } else if (uni < 9) {
    stream << 'V';
    for (auto i = 5; i != uni; ++i) {
      stream << 'I';
    }
  } else {
    stream << "IX";
  }

  return stream;
}

} // ns format

#endif // ROMAN_HPP

