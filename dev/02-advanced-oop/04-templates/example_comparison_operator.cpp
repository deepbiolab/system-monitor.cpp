#include <assert.h>

// TODO: Declare a generic, templatized function Max()
template <typename T>
T Max(T a, T b) {
  return a > b ? a : b;
}

int main() {
  assert(Max<int>(10, 50) == 50);
  assert(Max<double>(5.7, 1.436246) == 5.7);
}
