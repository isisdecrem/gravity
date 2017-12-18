#include "frame.h"
#include <iostream>

Frame::Frame() {

}

Frame::Frame(double xmin, double ymin, double xmax, double ymax) {
  minCorner = Vec2f(xmin, ymin);
  maxCorner = Vec2f(xmax, ymax);
}

Frame::Frame(const Vec2f& minCorner, const Vec2f& maxCorner) {
  this->minCorner = minCorner;
  this->maxCorner = maxCorner;
}

bool Frame::inFrame(const Vec2f& a) {
  return ((minCorner.x < a.x) && (maxCorner.x > a.x) && (minCorner.y < a.y) && (maxCorner.y > a.y));
}

bool Frame::inFrame(double x, double y) {
  return ((minCorner.x < x) && (maxCorner.x > x) && (minCorner.y < y) && (maxCorner.y > y));
}
