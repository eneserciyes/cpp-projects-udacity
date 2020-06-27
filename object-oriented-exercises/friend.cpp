#include <iostream>

class Rectangle;

class Square {
  friend class Rectangle;

 private:
  double side;

 public:
  Square(double side) : side(side) {}
};

class Rectangle {
 private:
  double width;
  double height;

 public:
  Rectangle(Square square) {
    width = square.side;
    height = square.side;
  }
  double Area() const { return width * height; }
};

int main() {
  Square square = Square(5);
  Rectangle rectangle = Rectangle(square);

  std::cout << rectangle.Area();
}