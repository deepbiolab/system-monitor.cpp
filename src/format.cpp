#include "format.h"

#include <string>

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  string hh = std::to_string(seconds / 3600);
  string mm = std::to_string(seconds % 3600 / 60);
  string ss = std::to_string(seconds % 60);
  if (hh.length() == 1) {
    hh = "0" + hh;
  }
  if (mm.length() == 1) {
    mm = "0" + mm;
  }
  if (ss.length() == 1) {
    ss = "0" + ss;
  }

  return hh + ":" + mm + ":" + ss;
}