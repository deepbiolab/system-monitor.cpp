/*
**Instructions**

Overloading can happen outside of an object-oriented context, too. In this
exercise, you will practice overloading a normal function that is not a class
member.

1. Create a function `hello()` that outputs, "Hello, World!"
2. Create a `class Human`.
3. Overload `hello()` by creating a function `hello(Human human)`. This function
should output, "Hello, Human!"
4. Create 2 more classes and use those classes to further overload the `hello()`
function.
*/

#include <iostream>

void hello() { std::cout << "Hello, World!\n"; }
class Human {};

void hello(Human human) { std::cout << "Hello, Human!\n"; }

class Cat {};

void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }



int main() {
	hello();
	hello(Human());
	hello(Cat());
}

