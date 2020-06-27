#include <math.h>

class MotionModel {
 public:
  virtual void Move(double v, double theta) = 0;

 protected:
  double theta;
  double x;
  double y;
};

class ParticleMotionModel : public MotionModel {
 public:
  void Move(double v, double phi) override {
    this->theta += phi;
    x += v * cos(theta);
    y += v * cos(theta);
  }
};

class BicycleMotionModel : public MotionModel {
 public:
  void Move(double v, double phi) override {
    theta += v / L * tan(phi);
    x += v * cos(theta);
    y += v * cos(theta);
  }

 private:
  double L{1};
};

int main() {}