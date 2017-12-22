#include "pixmap.h"
#include "vec2.h"

#include <algorithm>
#include <fstream>
#include <iostream>

Pixmap::Pixmap(int width, int height) {
  pixels = new unsigned char[width * height];
  this->width = width;
  this->height = height;

  clear();
}

Pixmap::~Pixmap() {
  delete[] pixels;
}

int Pixmap::area() {
  return width * height;
}

inline int Pixmap::pairToIndex(int x, int y) const {
  return y * width + x;
}

unsigned char Pixmap::getPixel(int index) const {
  return pixels[index];
}

unsigned char Pixmap::getPixel(int x, int y) const {
  return pixels[pairToIndex(x, y)];
}

unsigned char Pixmap::getPixel(const Vec2f& vec) const {
  return pixels[pairToIndex(vec.x, vec.y)];
}

void Pixmap::setPixel(const Vec2f& pos, unsigned char c) {
  if (0 <= pos.x && pos.x < width && 0 <= pos.y && pos.y < height) {
    pixels[pairToIndex((int)pos.x, (int)pos.y)] = c;
  }
}

void Pixmap::setPixel(int x, int y, unsigned char c) {
  if (0 <= x && x < width && 0 <= y && y < height) {
    pixels[pairToIndex(x, y)] = c;
  }
}

void Pixmap::setPixel(int index, unsigned char c) {
  pixels[index] = c;
}

void Pixmap::clear() {
  std::fill_n(pixels, area(), 255);
}

void Pixmap::exportToFile(std::string path) {
  std::ofstream file;
  file.open(path, std::ios::ios_base::binary | std::ios::ios_base::out);
  std::cout << path << std::endl;
  file << "P5\n" << std::to_string(width) << " " << std::to_string(height) << "\n255\n";
  for (int index = 0; index < area(); index++) {
    file << getPixel(index);
  }
  file.close();
}
