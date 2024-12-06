#include <cassert>
#include <iostream>

class Date {
 private:
  int day{1};
  int month{1};
  int year{2000};

 public:
  int Day() { return this->day; }
  void Day(int day) {
    if (day >= 1 && day <= 31) {
      this->day = day;
    }
  }
  int Month() { return this->month; }
  void Month(int month) {
    if (month >= 1 && month <= 12) {
      this->month = month;
    }
  }
  int Year() { return this->year; }
  void Year(int year) { this->year = year; }
};

// Test in main
int main() {
  Date date;
  date.Day(-1);
  date.Month(14);
  date.Year(2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == 2000);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year()
            << std::endl;
}
