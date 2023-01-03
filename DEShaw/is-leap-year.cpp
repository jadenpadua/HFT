#include <iostream>

bool is_leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int main() {
  int year;
  std::cout << "Enter a year: ";
  std::cin >> year;

  if (is_leap_year(year)) {
    std::cout << year << " is a leap year." << std::endl;
  } else {
    std::cout << year << " is not a leap year." << std::endl;
  }

  return 0;
}
