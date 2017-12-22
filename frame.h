#ifndef FRAME_DEFINED_
#define FRAME_DEFINED_

#include "vec2.h"

class Frame {
public:
  Vec2f minCorner;
  Vec2f maxCorner;
  Vec2f size;

  Frame();
  Frame(double, double, double, double, double, double);
  Frame(const Vec2f& minCorner, const Vec2f& maxCorner, const Vec2f& size);

  bool _inFrame(const Vec2f& a) const;
  bool _inFrame(double x, double y) const;
  double convertX(double x);
  double convertY(double y);

  Vec2f convertVec(const Vec2f&);
  Vec2f convertVec(double x, double y);
};

#endif
