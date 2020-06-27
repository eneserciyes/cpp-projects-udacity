#include <cassert>
#include <iostream>
#include <stdexcept>

class Pyramid {
 private:
  int length{0};
  int width{0};
  int height{0};

 public:
  Pyramid() {}

  Pyramid(int l, int w, int h) {
    setLength(l);
    setWidth(w);
    setHeight(h);
  }

  int getLength() const { return length; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setLength(int l) {
    if (l <= 0)
      throw std::invalid_argument("Length cannot be less than 0");
    length = l;
  }
  void setWidth(int w) {
    if (w <= 0)
      throw std::invalid_argument("Width cannot be less than 0");
    width = w;
  }
  void setHeight(int h) {
    if (h <= 0)
      throw std::invalid_argument("Height cannot be less than 0");
    height = h;
  }

  int volume() { return (length * width * height) / 3; }
};

int main() {
  Pyramid pyramid;
  try {
    pyramid = Pyramid(1, 2, 3);
  } catch (std::exception& e) {
    std::cout << "Exception caught";
  };
  assert(pyramid.getLength() == 1);
  assert(pyramid.getWidth() == 2);
  assert(pyramid.getHeight() == 3);
}