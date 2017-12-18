#include "camera.h"
#include "vec2.h"
#include <iostream>

Camera::Camera() {
  z = 0.2;
}

Camera::Camera(const Vec3f& position, const Vec3f& target, int z) {
  this->position = position;
  this->target = target;
  this->z = z;
}

Vec3f Camera::getTarget() const {
  return target;
}

Vec3f Camera::getPosition() const {
  return position;
}

double Camera::getZ() const {
  return z;
}

void Camera::setPosition(const Vec3f& a) {
  position = a;
}

void Camera::setTarget(const Vec3f& a) {
  target = a;
}

void Camera::setZ(double a) {
  z = a;
}

void Camera::setPosition(double x, double y, double z) {
  position.x = x;
  position.y = y;
  position.z = z;
}

void Camera::setTarget(double x, double y, double z) {
  target.x = x;
  target.y = y;
  target.z = z;
}

Vec2f Camera::project(const Vec3f& f) const {
  double c1, c2, s1, s2, r1, rdp2, r2, x, y, dx, dy, dz, d;

  Vec3f dp = target - position;

  r1 = std::sqrt(dp.x * dp.x + dp.y * dp.y);
  s1 = dp.x / r1;
  c1 = dp.y / r1;

  rdp2 = s1 * dp.x + c1 * dp.y;
  r2 = std::sqrt(rdp2 * rdp2 + dp.z * dp.z);

  c2 = rdp2 / r2;
  s2 = dp.z / r2;

  dx = f.x - position.x;
  dy = f.y - position.y;
  dz = f.z - position.z;

  x = (c1 * dx - s1 * dy);
  y = (-s1 * s2 * dx - c1 * s2 * dy + c2 * dz);

  d = s1 * c2 * dx + c1 * c2 * dy + s2 * dz;
  if (std::fabs(d) < z) return ErrorVector;

  return Vec2f(x / d, y / d);
}

Vec2f Camera::project(double xk, double yk, double zk) const {
  double c1, c2, s1, s2, r1, rdp2, r2, x, y, dx, dy, dz, d;

  Vec3f dp = target - position;

  r1 = std::sqrt(dp.x * dp.x + dp.y * dp.y);
  s1 = dp.x / r1;
  c1 = dp.y / r1;

  rdp2 = s1 * dp.x + c1 * dp.y;
  r2 = std::sqrt(rdp2 * rdp2 + dp.z * dp.z);

  c2 = rdp2 / r2;
  s2 = dp.z / r2;

  dx = xk - position.x;
  dy = yk - position.y;
  dz = zk - position.z;

  x = (c1 * dx - s1 * dy);
  y = (-s1 * s2 * dx - c1 * s2 * dy + c2 * dz);

  d = s1 * c2 * dx + c1 * c2 * dy + s2 * dz;
  if (std::fabs(d) < z) return ErrorVector;

  return Vec2f(x / d, y / d);
}
