/*
Your task is to design and implement class called `BankAccount`. This will be a
generic account defined by its account number, the name of the owner and the
funds available.

Complete the following steps:

1. Create class called `BankAccount`
2. Use typical info about bank accounts to design attributes, such as the
account number, the owner name, and the available funds.
3. Specify access so that member data are protected from other parts of the
program.
4. Create accessor and mutator functions for member data.
*/

#include <iostream>
#include <string>

class BankAccount {
 private:
  // TODO: declare member variables
  std::string owner;
  long int number;
  double funds;

 public:
  // TODO: declare setters or accessor function
  void set_owner(std::string owner);
  void set_number(long int number);
  void set_funds(double funds);

  // TODO: declare getters
  std::string get_owner() const;
  long int get_number() const;
  double get_funds() const;
};

// TODO: implement setters
void BankAccount::set_owner(std::string owner) { this->owner = owner; }

void BankAccount::set_number(long int number) { this->number = number; }

void BankAccount::set_funds(double funds) { this->funds = funds; }

// TODO: implement getters
std::string BankAccount::get_owner() const { return this->owner; }

long int BankAccount::get_number() const { return this->number; }

double BankAccount::get_funds() const { return this->funds; }

int main() {
  // TODO: instantiate and output a bank account
  BankAccount account;
  account.set_owner("Tim");
  account.set_number(123456);
  account.set_funds(1000);
  std::cout << "Owner: " << account.get_owner() << "\n";
  std::cout << "Number: " << account.get_number() << "\n";
  std::cout << "Funds: " << account.get_funds() << "\n";
}