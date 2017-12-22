#include <ostream>
#include <cmath>

#include "vec3.h"

#ifndef PARTICLE_DEFINED_
#define PARTICLE_DEFINED_

template <typename P = double, typename M = unsigned int>
class Particle {
public:
  Vec3<P> pos;
  Vec3<P> vel;
  M mass;
  P radius;

  Particle();
  Particle(Vec3<P> pos);
  Particle(Vec3<P> pos, Vec3<P> vel);
  Particle(Vec3<P> pos, Vec3<P> vel, M mass);

  void step();
  void step(double);
  void merge(const Particle<P,M>& p);
  void _calculateRadius();

  void move(const Vec3<P>&);
  void push(const Vec3<P>&);
  void move(P, P, P);
  void push(P, P, P);

  friend std::ostream& operator<<(std::ostream&, Particle<P,M>);
  std::string toString() const;

  Vec3<P>& getPos() const;
  Vec3<P>& getVel() const;
  void setPos(const Vec3<P>&);
  void setVel(const Vec3<P>&);
  void setPos(P, P, P);
  void setVel(P, P, P);

  static const int DENSITY = 1e2;
};

template <typename P, typename M> Particle<P, M>::Particle() {
  this->pos = Vec3<P>();
  this->vel = Vec3<P>();
  this->mass = 0;

  _calculateRadius();
}

template <typename P, typename M> Particle<P, M>::Particle(Vec3<P> pos) {
  this->pos = pos;
  this->vel = Vec3<P>();
  this->mass = 0;

  _calculateRadius();
}

template <typename P, typename M>
Particle<P, M>::Particle(Vec3<P> pos, Vec3<P> vel) {
  this->pos = pos;
  this->vel = vel;
  this->mass = 0;

  _calculateRadius();
}

template <typename P, typename M>
Particle<P, M>::Particle(Vec3<P> pos, Vec3<P> vel, M mass) {
  this->pos = pos;
  this->vel = vel;
  this->mass = mass;

  _calculateRadius();
}

template <typename P, typename M> void Particle<P, M>::step() { pos += vel; }

template <typename P, typename M> void Particle<P, M>::step(double factor) {
  Vec3<P> velc{vel};
  velc *= factor;
  pos += velc;
}

template <typename P, typename M> Vec3<P> &Particle<P, M>::getPos() const {
  return pos;
}

template <typename P, typename M> Vec3<P> &Particle<P, M>::getVel() const {
  return vel;
}

template <typename P, typename M>
void Particle<P, M>::setPos(const Vec3<P> &vec) {
  pos = vec;
}

template <typename P, typename M>
void Particle<P, M>::setVel(const Vec3<P> &vec) {
  vel = vec;
}

template <typename P, typename M> void Particle<P, M>::setPos(P x, P y, P z) {
  pos.x = x;
  pos.y = y;
  pos.z = z;
}

template <typename P, typename M> void Particle<P, M>::setVel(P x, P y, P z) {
  pos.x = x;
  pos.y = y;
  pos.z = z;
}

template <typename P, typename M>
void Particle<P, M>::merge(const Particle<P, M> &p) {
  double massRatio = mass / p.mass;

  pos = (pos * massRatio + p.pos) / (1 + massRatio);
  vel = (vel * massRatio + p.vel);
  mass += p.mass;
}

template <typename P, typename M>
void Particle<P, M>::_calculateRadius() {
  radius = std::cbrt(mass / DENSITY);
}

template <typename P, typename M>
void Particle<P, M>::move(const Vec3<P> &vec) {
  pos += vec;
}

template <typename P, typename M>
void Particle<P, M>::push(const Vec3<P> &vec) {
  vel += vec;
}

template <typename P, typename M> void Particle<P, M>::move(P x, P y, P z) {
  pos.add(x, y, z);
}

template <typename P, typename M> void Particle<P, M>::push(P x, P y, P z) {
  vel.add(x, y, z);
}

template <typename P, typename M> std::string Particle<P, M>::toString() const {
  return "Pos: " + pos.toString() + "; Vel: " + vel.toString() +
         "; Mass: " + std::to_string(mass) +
         "; Radius: " + std::to_string(radius);
}

template <typename P, typename M>
std::ostream &operator<<(std::ostream &os, Particle<P, M> p) {
  os << "Pos: " << p.pos << "; Vel: " << p.vel
     << "; Mass: " + std::to_string(p.mass)
     << "; Radius: " << std::to_string(p.radius);
  return os;
}

#endif
