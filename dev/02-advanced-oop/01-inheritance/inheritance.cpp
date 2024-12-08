/*
1. Add a new member variable to `class Vehicle`.
2. Output that new member in `main()`.
3. Derive a new class from `Vehicle`, alongside `Car` and `Bicycle`.
4. Instantiate an object of that new class.
5. Print the object.
*/

#include <iostream>
#include <string>
using std::string;

class Vehicle {
  public:
    int    wheels = 0;
    string color  = "blue";
    float  weight = 0.0f;

    void Print() const {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels, ";
        std::cout << weight << " kG.\n";
    }
};

class Car : public Vehicle {
  public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
  public:
    bool kickstand = true;
};

int main() {
    Car car;
    car.wheels  = 4;
    car.sunroof = true;
    car.weight  = 500;
    car.Print();
    if (car.sunroof) {
        std::cout << "And a sunroof!\n";
    }
};
