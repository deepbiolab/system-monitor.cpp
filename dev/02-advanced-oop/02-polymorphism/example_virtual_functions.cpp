// Example solution for Shape inheritance
#include <assert.h>

#include <cmath>

// TODO: Define pi
#define PI 3.1415926;

// TODO: Define the abstract class Shape
class Shape {
    // TODO: Define public virtual functions Area() and Perimeter()
  public:
    virtual double Area() const      = 0;
    virtual double Perimeter() const = 0;
    // TODO: Append the declarations with = 0 to specify pure virtual functions
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : public Shape {
  public:
    // TODO: Declare public constructor
    Rectangle(double width, double height) : width_(width), height_(height) {}

    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const override { return width_ * height_; }

    double Perimeter() const override { return 2 * width_ + 2 * height_; }

    // TODO: Declare private attributes width and height
  private:
    double width_;
    double height_;
};

// TODO: Define Circle to inherit from Shape
class Circle : public Shape {
    // TODO: Declare public constructor
  public:
    Circle(double radius) : radius_(radius) {}

    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const override { return pow(radius_, 2) * PI; }

    double Perimeter() const override { return 2 * radius_ * PI; }

    // TODO: Declare private member variable radius
  private:
    double radius_;
};

// Test in main()
int main() {
    double epsilon = 0.1;  // useful for doubleing point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
}
