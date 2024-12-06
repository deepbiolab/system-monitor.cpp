#include <cassert>
#include <iostream>

class Date {
 public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);

 private:
  int day_{1};
  int month_{1};
  int year_{0};
  int DaysInMonth(int year, int month) const;
  bool LeapYear(int year) const;
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

bool Date::LeapYear(int year) const {
  if (year % 4 == 0) {
    if (year % 100 != 0 || year % 400 == 0) {
      return true;
    }
  }
  return false;
}

int Date::DaysInMonth(int year, int month) const {
  if (month == 2) return LeapYear(year) ? 29 : 28;

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= this->DaysInMonth(this->Year(), this->Month()))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(29, 2, 2024); // 2024 is leap year
  std::cout << date.Day() << std::endl;
  assert(date.Day() == 29);
  assert(date.Month() == 2);
  assert(date.Year() == 2024);
}