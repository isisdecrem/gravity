#include <iostream>
#include <vector>
#include "particle.h"
#include "frame.h"

int main() {
  typedef Particle<> ParticleType;
  ParticleType p;

  p.push(1,2,3);
  p.move(0,1,1);

  Frame j = Frame(-1, -1, 1, 1);

  j.setPosition(4, 5, 10);
  j.setTarget(0, 0, 0);

  std::vector<Vec3<double>> l;

  for (int i = 0; i < 50; i++) {
    l.push_back(Vec3<double>(20 * sin(i), 5 * cos(i), 4 * cos(i)));
  }

  for (auto& k : l) {
    Vec2f q = j.project(k);
    if (j.inFrame(q)) {
      std::cout << q.x << "\t" << q.y << '\n';
    }
  }
}
