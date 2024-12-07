/*
Declare:

1. A constructor function that takes the radius as an argument
2. A member function that returns the [volume](https://www.google.com/search?q=sphere+volume)

**Directions**

1. Define a class called `Sphere`.
2. Add one private member variable: `radius`.
3. Define a constructor to initialize the radius.
4. Define an accessor method that returns the radius.
5. Define a member function to return the volume of the sphere.
6. Write a `main()` function to initialize an object of type `Sphere`.
*/


#include <cassert>
#include <cmath>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
 public:
  // Constructor
  Sphere(float radius) : radius_(radius), volume_((4.0f/3.0f) * pi_ * pow(Radius(), 3)) {
      if (radius < 0) { throw std::invalid_argument("Radius must be positive"); }
  }
  // Accessors
  float Radius() const { return radius_; }
  float Volume() const { return volume_; }

 private:
  // Private members
  const float pi_{3.14159265358979323846};
  const float radius_;
  const float volume_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}