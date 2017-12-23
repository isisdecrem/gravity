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
  c.setPosition(3e7, 1.5e7, 2.5e7);
  c.setTarget(0, 0, 0);

  Universe u = Universe();

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_real_distribution<> dist(-300000, 300000);
  std::uniform_real_distribution<> veldist(-0.01, 0.01);

  for (int i = 0; i < 1000000; i++) {
    double x = dist(rng);
    double y = -dist(rng);
    double z = dist(rng);

    u.addParticle(Star(Vec3f(x, y, z), Vec3f(x / 300000, y / 300000, z / 300000), 2));
  }

  for (int i = 0; i < 20000; i++) {
    std::cout << "Step: " << i << std::endl;
    u.step(1e5, 10000);

    k.clear();
    u.project(c, k);

    k.exportToFile("/Users/timoothy/Desktop/particles/f" + std::to_string(i) + ".pgm");
  }
}
