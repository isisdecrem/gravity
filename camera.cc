#include "camera.h"
#include "vec2.h"

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

Frame& Camera::getFrame() {
  return frame;
}

void Camera::setFrame(Frame f) {
  frame = f;
}

void Camera::setFrame(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6) {
  frame = Frame(arg1, arg2, arg3, arg4, arg5, arg6);
}

void Camera::setFrame(const Vec2f& arg1, const Vec2f& arg2, const Vec2f& arg3) {
  frame = Frame(arg1, arg2, arg3);
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

Vec2f Camera::project(const Vec3f& f) {
  return frame.convertVec(_projectNoConvert(f));
}

Vec2f Camera::project(double xk, double yk, double zk) {
  return frame.convertVec(_projectNoConvert(xk, yk, zk));
}

Vec2f Camera::_projectNoConvert(const Vec3f& f) const {
  return _projectNoConvert(f.x, f.y, f.z);
}

Vec2f Camera::_projectNoConvert(double xk, double yk, double zk) const {
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

  return Vec2f(x / d, -y / d);
}

bool Camera::_inFrame(const Vec2f& v) const {
  return frame._inFrame(v);
}

bool Camera::_inFrame(double x, double y) const {
  return frame._inFrame(x, y);
}
