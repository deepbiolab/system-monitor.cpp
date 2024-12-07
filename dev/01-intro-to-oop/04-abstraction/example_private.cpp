/*
**Directions**

In this exercise, you'll update the `class Sphere` so that it becomes possible to change the radius of a sphere after it has been initialized. In order to do this, you'll move the two class [class invariants](https://en.wikipedia.org/wiki/Class_invariant) into private member functions.

1. Add a mutator method to change the radius of an existing `Sphere`.
2. Copy the range-check on `radius_` from the class constructor into the mutator method.
3. Copy the `volume_` calculation from the class constructor into the same mutator method.
4. Verify that the mutator method successfully updates both the radius and the volume and the class still functions correctly.
*/


#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
 public:
  Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3)) {
    if (radius <= 0) throw std::invalid_argument("radius must be positive");
  }

  int Radius() const { return radius_; }
  int Volume() const { return volume_; }

  // TODO: mutators
  void Radius(float radius) {
      if (radius <= 0) throw std::invalid_argument("radius must be positive");
      radius_ = radius;
      volume_ = pi_ * 4 / 3 * pow(radius_, 3);
  }

 private:
  float const pi_{3.14159};
  int radius_;
  float volume_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  sphere.Radius(3);
  assert(sphere.Radius() == 3);
  assert(abs(sphere.Volume() - 113.1) < 1);

  bool caught{false};
  try {
    sphere.Radius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}