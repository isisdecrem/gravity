#ifndef CAMERA_DEFINED_
#define CAMERA_DEFINED_

#include "vec2.h"
#include "vec3.h"
#include "frame.h"

class Camera {
private:
  Vec3f target;
  Vec3f position;
  double z;

  Frame frame;
public:
  Camera();
  Camera(const Vec3f&, const Vec3f&, int z);

  Vec3f getTarget() const;
  Vec3f getPosition() const;
  double getZ() const;
  Frame& getFrame();

  void setTarget(const Vec3f&);
  void setPosition(const Vec3f&);
  void setTarget(double, double, double);
  void setPosition(double, double, double);
  void setZ(double);
  void setFrame(Frame);

  void setFrame(double, double, double, double, double, double);
  void setFrame(const Vec2f&, const Vec2f&, const Vec2f&);

  bool _inFrame(const Vec2f& a) const;
  bool _inFrame(double x, double y) const;

  Vec2f _projectNoConvert(const Vec3f&) const;
  Vec2f _projectNoConvert(double xk, double yk, double zk) const;

  Vec2f project(const Vec3f&);
  Vec2f project(double xk, double yk, double zk);
};

#endif
