/*
We will create a setter method that receives data as an argument an
converts it to a different type. Specifically, you will receive a string as
input and convert it to a character array.

1. Create a class called `Car`.

2. Create 3 member variables: `horsepower`, `weight` and `brand`.
The `brand` attribute must be a character array.

3. Create accessor and mutator functions for all member data.
The mutator function for `brand` must accept a C++ string as a parameter and
convert that string into a [C-style
string)](https://www.learncpp.com/cpp-tutorial/66-c-style-strings/) (a
character array ending in null character) to set the value of `brand`.

4. The accessor function for the `brand` must return a string, so in this
function you first will need to convert `brand` to `std::string`, and then
return it.
*/

#include <cstring>
#include <iostream>
#include <string>

class Car {
  // TODO: Declare private attributes
 private:
  int horsepower;
  float weight;
  char* brand;

  // TODO: Declare getter and setter for brand
 public:
  int get_horsepower() const;
  float get_weight() const;
  std::string get_brand() const;

  void set_horsepower(int hourse_power);
  void set_weight(float weight);
  void set_brand(std::string brand);
};

// Define setters
void Car::set_brand(std::string brand) {
  this->brand = new char[brand.size() + 1];
  std::strncpy(this->brand, brand.c_str(), brand.size());
}
void Car::set_horsepower(int horse_power) { this->horsepower = horse_power; }
void Car::set_weight(float weight) { this->weight = weight; }

// Define getters
std::string Car::get_brand() const { return this->brand; }
int Car::get_horsepower() const { return this->horsepower; }
float Car::get_weight() const { return this->weight; }

// Test in main()
int main() {
  Car car;
  car.set_brand("Peugeot");
  std::cout << car.get_brand() << "\n";
}