/*
**Instructions**

In this exercise, you will start with a `LineSegment` struct and create a
`Circle` class.

Note that you will compose `Circle` from `LineSegment`, instead of inheriting
`Circle` from `LineSegment`. Specifically, the `length` attribute from
`LineSegment` will become the circle's radius.

1. Create a struct `LineSegment`.
2. Declare an attribute `length` in struct `LineSegment`.
3. Define pi (3.14159) with a macro.
4. Create a class `Circle`, composed of a `LineSegment` that represents the
circle's radius. Use this radius to calculate the area of the circle (area of a
circle = πr^2).
5. Verify the behavior of `Circle` in `main()`.
*/

#include <assert.h>

#include <cmath>
#include <iostream>

// Define pi as macro
#define PI 3.1415926;

// Define Line Class
struct LineSegment {
    double length;
};

// Define Circle subclass
class Circle {
  private:
    LineSegment radius_;
    double      area_;

  public:
    Circle(LineSegment & radius) : radius_(radius) { area_ = pow(radius_.length, 2) * PI; }

    double Area() { return area_; }
};

// Test in main()
int main() {
    LineSegment radius{ 3 };
    Circle      circle(radius);
    assert(int(circle.Area()) == 28);
}
