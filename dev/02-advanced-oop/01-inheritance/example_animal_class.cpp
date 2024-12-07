/*
**Instructions**

1. Define a class `Animal`.
2. Define 3 member variables: `color`, `name`, `age`.
3. Define a derived class `Snake` that inherits from the base class `Animal`.
4. Create a member variable `length` for the `Snake` class.
5. Create a derived class `Cat` that inherits from the base class `Animal`.
6. Create a member variable `height` for the `Cat` class.
7. Create `MakeSound()` member functions for each of the derived classes.
8. In the `main()` function instantiate `Snake` and `Cat` objects. Initialize both their unique and derived attributes. Program them to make a sound.
*/
#include <iostream>
#include <string>

// Define base class Animal
class Animal {
	public:
		std::string color;
		std::string name;
		int age;
};

// Declare derived class Snake
class Snake : public Animal {
	public:
		float length;
		void MakeSound() { std::cout << "ssss...\n"; }
};

// Declare derived class Cat
class Cat : public Animal {
	public:
		float height;
		void MakeSound() { std::cout << "meow...\n"; }
};

// Test in main()
int main() {
	Snake snake;
	snake.length = 10;
	snake.MakeSound();
	Cat cat;
	cat.height = 8;
	cat.MakeSound();

}