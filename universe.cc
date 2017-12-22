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
  step(1);
}

inline double sq(double s) {
  return s * s;
}

void Universe::gravitate(int i1, int i2, double factor) {
  if (i1 == i2) return;
  Star& p1 = particles[i1];
  Star& p2 = particles[i2];

  auto delta = p2.pos - p1.pos;
  double force = factor * G / (sq(p2.pos.x - p1.pos.x) + sq(p2.pos.y - p1.pos.y) + sq(p2.pos.z - p1.pos.z));

  Vec3f deltac{delta};
  deltac *= -force * p2.mass;

  p1.vel += deltac;
  deltac = delta;

  deltac *= force * p1.mass;
  p2.vel += deltac;
}

void Universe::step(double factor) {
  for (int i = 0; i < count(); i++) {
    for (int j = i + 1; j < count(); j++) {
      gravitate(i, j, factor);
    }
  }

  int correctCount = count();

  for (int i = 0; i < correctCount; i++) {
    for (int j = i + 1; j < correctCount; j++) {
      if (particles[i].pos.distance(particles[j].pos) < particles[i].radius + particles[j].radius) {
        mergeParticles(i, j);
        correctCount--;
      }
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
