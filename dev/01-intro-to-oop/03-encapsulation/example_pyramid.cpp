/*
1. Create a class: `Pyramid`.
2. Create 3 attributes: `length`, `width`, and `height`.
3. Create a constructor to initialize all the attributes.
4. Create accessor and mutator functions for all attributes.
5. Think about the appropriate invariants and enforce them by throwing
exceptions.
6. Create a member function to calculate the volume of the pyramid.
7. Optional: create a member function to calculate the surface area of the
pyramid.
*/

#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
 private:
  int length_;
  int width_;
  int height_;

 public:
  // constructor
  Pyramid(int length, int width, int height);

  // accessors
  int Length() const;
  int Width() const;
  int Height() const;

  // mutators
  void Length(int length);
  void Width(int width);
  void Height(int height);

  // Volume function
  int Volume();
};

Pyramid::Pyramid(int length, int width, int height)
{
	if (length <= 0) {
		throw std::invalid_argument("Lenght must be positive.");
	}
	if (width <=0) {
		throw std::invalid_argument("Width must be positive.");
	}
	if (height <= 0) {
		throw std::invalid_argument("Height must be positive.");
	}
	this->Length(length);
	this->Height(height);
	this->Width(width);
		
}

int Pyramid::Length() const { return this->length_; }
int Pyramid::Width() const { return this->width_; }
int Pyramid::Height() const { return this->height_; }

void Pyramid::Length(int length) {
	this->length_ = length; 
}
void Pyramid::Width(int width) { 
	this->width_ = width; 
}
void Pyramid::Height(int height) { 
	this->height_ = height; 
}

int Pyramid::Volume() {
  return (this->height_ * this->width_ * this->length_) / 3;
}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}