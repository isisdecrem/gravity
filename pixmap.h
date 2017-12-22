#ifndef PIXMAP_DEFINED_
#define PIXMAP_DEFINED_

#include "vec2.h"
#include <string>

class Pixmap {
public:
  unsigned char* pixels;
  int width;
  int height;

  Pixmap(int width, int height);
  ~Pixmap();

  int area();

  inline int pairToIndex(int, int) const;

  unsigned char getPixel(int index) const;
  unsigned char getPixel(int x, int y) const;
  unsigned char getPixel(const Vec2f& pos) const;

  void setPixel(const Vec2f& pos, unsigned char c);
  void setPixel(int index, unsigned char c);
  void setPixel(int x, int y, unsigned char c);
  void clear();

  void exportToFile(std::string file);
};

#endif
