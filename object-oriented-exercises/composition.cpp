#include <cassert>
#include <iostream>

class LineSegment {
 public:
  double getLength() { return length; }
  LineSegment(double length) : length(length) {}

 protected:
  double length;
};

class Circle {
 private:
  const LineSegment lineSegment;
  const double area;

 public:
  double constexpr static pi = 3.14159;
  double getArea() { return area; }
  Circle(LineSegment line)
      : lineSegment(line), area(line.getLength() * line.getLength() * pi) {}
};

int main() {
  LineSegment line = LineSegment(5);

  Circle circle(line);

  assert(circle.getArea() - 78.5397 < 0.1);
  std::cout << circle.getArea();
}