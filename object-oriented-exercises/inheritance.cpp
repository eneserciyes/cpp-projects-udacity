#include <iostream>
#include <string>

class Vehicle {
 public:
  int wheels = 0;

  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels! "
              << "It's " << mass << "kg!\n";
  }

 private:
 protected:
  float mass;
  std::string color = "blue";
};

class Car : public Vehicle {
 public:
  bool sunroof = false;
};

class Truck : public Vehicle {
 public:
  bool kickstand = true;
};

class Bicycle : public Vehicle {
 public:
  float getMass() { return mass; }
  void setMass(float mass) { this->mass = mass; }
  std::string getColor() { return color; }
  void setColor(std::string color) { this->color = color; }
};

int main() {
  Bicycle bicycle{};
  bicycle.wheels = 2;
  bicycle.setColor("red");
  bicycle.setMass(15.0f);

  bicycle.Print();
}