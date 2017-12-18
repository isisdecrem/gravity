#ifndef FRAME_DEFINED_
#define FRAME_DEFINED_

#include "camera.h"

class Frame : public Camera {
public:
  Vec2f minCorner;
  Vec2f maxCorner;

  Frame();
  Frame(double, double, double, double);
  Frame(const Vec2f&, const Vec2f&);

  bool inFrame(const Vec2f& a);
  bool inFrame(double x, double y);
};

#endif
