#include <cassert>
#include <iostream>
#include <string>

class Animal {
 public:
  virtual std::string Talk() const;
};

class Cat {
 public:
  std::string Talk() const { return std::string("Meow"); }
};

class Dog {
 public:
  std::string Talk() const { return "Barrr"; }
};

int main() {
  Dog dog;
  Cat cat;
  assert(dog.Talk() == "Barrr");
  assert(cat.Talk() == "Meow");
}