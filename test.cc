#include <iostream>
#include "particle.h"

int main() {
  typedef double lengthUnit;
  typedef unsigned int massUnit;

  typedef Particle<lengthUnit, massUnit> ParticleType;
  ParticleType p;

  p.push(1,2,3);
  p.move(0,1,1);

  std::cout << p.toString() << std::endl;
}
