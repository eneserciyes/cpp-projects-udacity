#include <iostream>
#include <string>

class Human;

void hello() {
  std::cout << "Hello, World";
}

class Human {
 public:
  std::string const name;
  Human(std::string name) : name(name) {}
};

void hello(Human human) {
  std::cout << "Hello, " << human.name;
}

int main() {}