#include <assert.h>

#include <cmath>

// TODO: Define PI
#define PI 3.1415926

// TODO: Declare abstract class VehicleModel
class VehicleModel {
 public:
  // TODO: Declare virtual function Move()
  virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel {
 public:
  // TODO: Override the Move() function
  void Move(double v, double phi) override;
  // TODO: Define x, y, and theta
  double x = 0;
  double y = 0;
  double theta = 0;
};

void ParticleModel::Move(double v, double phi) {
  theta += phi;
  x += v * cos(theta);
  y += v * cos(theta);
}

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel {
 public:
  // TODO: Define L
  double L = 1;
  // TODO: Override the Move() function
  void Move(double v, double phi) override {
    theta += v / L * tan(phi);
    x += v * cos(theta);
    y += v * cos(theta);
  }
};

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}