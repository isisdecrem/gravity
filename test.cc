#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "particle.h"
#include "frame.h"
#include "pixmap.h"
#include "universe.h"

#define PI 3.14159265359

int main() {
  const int width = 1024;
  const int height = 768;

  const double size = 0.0004;

  Pixmap k = Pixmap(width, height);

  std::cout << k.width << " " << k.height << " " << k.area() << "\n";

  Frame f = Frame(-width * size, -height * size, width * size, height * size, width, height);
  Camera c = Camera();

  c.setFrame(f);
  c.setPosition(100, 100, 100);
  c.setTarget(0, 0, 0);

  Universe u = Universe();

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_real_distribution<> dist(-100, 100);
  std::uniform_real_distribution<> veldist(-2, 2);

  for (int i = 0; i < 10000; i++) {
    u.addParticle(Star(Vec3f(dist(rng), dist(rng), dist(rng)), Vec3f(veldist(rng), veldist(rng), veldist(rng)), 2));
  }

  for (int i = 0; i < 100; i++) {
    std::cout << "Step: " << i << std::endl;
    u.step(0.1);

    k.clear();
    u.project(c, k);

    k.exportToFile("/Users/timoothy/Desktop/particles/test" + std::to_string(i) + ".pgm");
  }
}
