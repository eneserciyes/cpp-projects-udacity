#include <math.h>

#include <iostream>
#include <stdexcept>

class Sphere {
 private:
  double radius;
  static float constexpr pi{M_PI};

 public:
  Sphere(double r) { SetRadius(r); }

  void SetRadius(double r) {
    if (radius <= 0)
      throw std::invalid_argument("radius must be positive");
    radius = r;
  }
  double GetRadius() const { return radius; }

  double Volume() const { return 4 * std::pow(radius, 3) * pi / 3; }
  double static Volume(double r) { return 4 * std::pow(r, 3) * pi / 3; }
};

int main() {
  Sphere sphere = Sphere(3);

  std::cout << sphere.Volume() << "\n";
  std::cout << Sphere::Volume(3) << "\n";
}