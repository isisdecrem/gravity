#include "universe.h"
#include <iostream>

Universe::Universe() {

}

void Universe::addParticle(Star star) {
  particles.push_back(star);
}

int Universe::count() {
  return particles.size();
}

void Universe::removeParticle(int index) {
  if (index != count() - 1) {
    particles[index] = particles.back();
  }
  particles.pop_back();
}

void Universe::mergeParticles(int index1, int index2) {
  if (index1 == index2) return;
  particles[index1].merge(particles[index2]);

  removeParticle(index2);
}

void Universe::step() {
  step(1, 1);
}

inline double sq(double s) {
  return s * s;
}

double tempForce;
Vec3f tempDeltac = Vec3f();
Vec3f tempDelta = Vec3f();

void Universe::gravitate(int i1, int i2, double factor) {
  if (i1 == i2) return;
  Star& p1 = particles[i1];
  Star& p2 = particles[i2];

  tempDelta = p2.pos - p1.pos;
  tempForce = factor * G / (sq(p2.pos.x - p1.pos.x) + sq(p2.pos.y - p1.pos.y) + sq(p2.pos.z - p1.pos.z));

  tempDeltac = tempDelta;
  tempDeltac *= -tempForce * p2.mass;

  p1.vel += tempDeltac;

  tempDelta *= tempForce * p1.mass;
  p2.vel += tempDelta;
}

void Universe::step(double factor, int coarseness) {
  for (int i = 0; i < count(); i++) {
    for (int j = i + 1; j < count(); j += coarseness) {
      gravitate(i, j, factor * coarseness);
    }
  }

  for (int i = 0; i < count(); i++) {
    particles[i].step(factor);
  }
}

Star& Universe::getParticle(int index) {
  return particles[index];
}

void Universe::project(Camera& c, Pixmap& p) {
  for (int i = 0; i < count(); i++) {
    Vec2f v = c.project(particles[i].pos);
    p.setPixel(v, 0);
  }
}
