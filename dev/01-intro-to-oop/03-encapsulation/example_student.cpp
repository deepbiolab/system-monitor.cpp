/*
1. Add 3 private member variables to the class:
   - Name
   - Grade (e.g. 9th grade)
   - Grade Point Average
2. Write a public constructor function to set the private attributes.
3. Create public member functions to set each of the member variables. Before
setting the values verify that:
   - Grade is from 0 (kindergarten) to 12
   - GPA is from 0.0 to 4.0
   - The function must either throw an exception if any of the invariants are
violated
4. Within the `main()` (outside of the class), declare an object of type
`Student` and test out each of the member function calls.

*/

#include <cassert>
#include <stdexcept>
#include <string>

class Student {
 private:
  std::string name_;
  int grade_;
  float gpa_;
  void validate_grade() {
	if (Grade() < 0 || Grade() > 12) {
		throw std::invalid_argument("Grade must between 1 and 12.");
	}
  }
  void validate_gpa() {
	if (Gpa() < 0 || Gpa() > 4.0) {
		throw std::invalid_argument("GPA must between 0 and 4.0");
	}
  }

 public:
  Student(std::string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) {
	validate_gpa();
	validate_grade();
  }

  // Accessor functions
  std::string Name() const { return name_; }
  int Grade() const { return grade_; }
  float Gpa() const { return gpa_; }

  // Mutator funcitons
  void Name(std::string name) {
	name_ = name;
  }

  void Grade(int grade) {
	grade_ = grade;
	validate_grade();
  }

  void Gpa(float gpa) {
	gpa_ = gpa;
	validate_gpa();
  }
};

int main() {
  Student student("Tim", 8, 4.0);

  bool exception{false};
  try {
    student.Grade(-1);
  } catch (...) {
    exception = true;
  }
  assert(exception == true);
}