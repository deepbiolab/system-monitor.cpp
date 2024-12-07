/*
1. Declare a class `Rectangle`.
2. Define a class `Square` as friend of `Rectangle`
   - Add a public constructor to `Square` class, initialize side.
   - Add friend class `Rectangle`.
   - Add private attribute side to `Square`.
3. Define class `Rectangle`
   - Add public declarations of the class constructor and *Area()* method.
   - Add private attributes *width* and *height*.
4. Outside class `Rectangle`, and using class scope of resolution (::).
   - Define a `Rectangle` constructor that takes a `Square`.
   - Define *Area()* to compute the area of `Rectangle`.
*/

// Example solution for Rectangle and Square friend classes
#include <assert.h>
// Declare class Rectangle
class Rectangle;
// Define class Square as friend of Rectangle
// Add public constructor to Square, initialize side
// Add friend class Rectangle
// Add private attribute side to Square
class Square {
 private:
  int side_;

 public:
  Square(int side) : side_(side) {}
  friend class Rectangle;
};

// Define class Rectangle
// Add public declarations of the class constructor and Area() method
// Add private attributes width, height
class Rectangle {
 private:
  float width_;
  float height_;

 public:
  Rectangle(const Square& square);
  float Area() const;
};


// Outside class Rectangle and using class scope of resolution (::)

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square& square)
    : width_(square.side_), height_(square.side_) {}

// Define Area() to compute area of Rectangle
float Rectangle::Area() const { return width_ * height_; }

//  Update main() to pass the tests
int main() {
  Square square(4);
  Rectangle rectangle(square);
  assert(rectangle.Area() == 16);
}