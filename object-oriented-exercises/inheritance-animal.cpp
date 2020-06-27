#include <iostream>
#include <string>

class Animal {
 public:
  std::string color;
  std::string name;
  int age;
};

class Snake : public Animal {
 public:
  double length;
  std::string MakeSound() { return "Tsssssss"; }
};

int main() {
  Snake snake;
  std::cout << "Snake says " << snake.MakeSound();
}