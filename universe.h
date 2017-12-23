#ifndef UNIVERSE_DEFINED_
#define UNIVERSE_DEFINED_

#include "particle.h"
#include "camera.h"
#include "pixmap.h"
#include <vector>

typedef Particle<double, int> Star;

class Universe {
public:
  std::vector<Star> particles;
  static constexpr double G = 0.0000001560698;

  Universe();

  int count();
  void addParticle(Star);
  void removeParticle(int);
  void mergeParticles(int, int);
  Star& getParticle(int);
  int particleCount();

  void gravitate(int, int, double);
  void step();
  void step(double, int);
  void project(Camera&, Pixmap&);
};

#endif
