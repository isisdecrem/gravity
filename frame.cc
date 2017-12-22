#include "frame.h"
#include <iostream>

Frame::Frame() {

}

Frame::Frame(double xmin, double ymin, double xmax, double ymax, double sizex, double sizey) {
  minCorner = Vec2f(xmin, ymin);
  maxCorner = Vec2f(xmax, ymax);
  size = Vec2f(sizex, sizey);
}

Frame::Frame(const Vec2f& minCorner, const Vec2f& maxCorner, const Vec2f& size) {
  this->minCorner = minCorner;
  this->maxCorner = maxCorner;
  this->size = size;
}

bool Frame::_inFrame(const Vec2f& a) const {
  return ((minCorner.x < a.x) && (maxCorner.x > a.x) && (minCorner.y < a.y) && (maxCorner.y > a.y));
}

bool Frame::_inFrame(double x, double y) const {
  return ((minCorner.x < x) && (maxCorner.x > x) && (minCorner.y < y) && (maxCorner.y > y));
}

double Frame::convertX(double x) {
  return (x - minCorner.x) / (maxCorner.x - minCorner.x) * size.x;
}

double Frame::convertY(double y) {
  return (y - minCorner.y) / (maxCorner.y - minCorner.y) * size.y;
}

Vec2f Frame::convertVec(const Vec2f& vec) {
  return Vec2f(convertX(vec.x), convertY(vec.y));
}

Vec2f Frame::convertVec(double x, double y) {
  return Vec2f(convertX(x), convertY(y));
}
