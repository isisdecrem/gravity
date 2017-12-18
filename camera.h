#ifndef CAMERA_DEFINED_
#define CAMERA_DEFINED_

#include "vec2.h"
#include "vec3.h"

typedef Vec2<double> Vec2f;
typedef Vec3<double> Vec3f;

const Vec2f ErrorVector(std::numeric_limits<double>::min(), std::numeric_limits<double>::min());

class Camera {
private:
  Vec3f target;
  Vec3f position;
  double z;
public:
  Camera();
  Camera(const Vec3f&, const Vec3f&, int z);

  Vec3f getTarget() const;
  Vec3f getPosition() const;
  double getZ() const;

  void setTarget(const Vec3f&);
  void setPosition(const Vec3f&);
  void setTarget(double, double, double);
  void setPosition(double, double, double);
  void setZ(double);

  Vec2f project(const Vec3f&) const;
  Vec2f project(double xk, double yk, double zk) const;
};

#endif
