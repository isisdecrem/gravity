#ifndef VEC2_DEFINED_
#define VEC2_DEFINED_

#include <ostream>
#include <cmath>
#include <limits>

template <typename T = double>
struct Vec2 {
  T x;
  T y;

  Vec2() {
    x = 0;
    y = 0;
  }

  Vec2(T x, T y) {
    this->x = x;
    this->y = y;
  }

  T distance() const;
  T distance(T, T) const;
  T distance(const Vec2&) const;

  bool operator==(const Vec2&) const;
  Vec2 operator+(const Vec2&) const;
  Vec2 operator-(const Vec2&) const;
  Vec2 operator*(T) const;
  Vec2 operator/(T) const;

  template <typename U>
  friend std::ostream& operator<<(std::ostream&, const Vec2<U>&);
  std::string toString() const;

  void operator+=(const Vec2&);
  void operator-=(const Vec2&);
  void operator*=(T);
  void operator/=(T);

  void add(T, T);
  void sub(T, T);
  void stretch(T);
  void squish(T);
};

template <typename T>
T Vec2<T>::distance() const {
  return std::sqrt(x * x + y * y);
}

template <typename T>
T Vec2<T>::distance(T xx, T yy) const {
  T a = x - xx;
  T b = y - yy;

  return std::sqrt(a * a + b * b);
}

template <typename T>
T Vec2<T>::distance(const Vec2& vec) const {
  return distance(vec.x, vec.y);
}

template <typename T>
bool Vec2<T>::operator==(const Vec2& vec) const {
  return (x == vec.x && y == vec.y);
}

template <typename T>
Vec2<T> Vec2<T>::operator+(const Vec2& vec) const {
  Vec2 result;

  result.x = vec.x + x;
  result.y = vec.y + y;

  return result;
}

template <typename T>
Vec2<T> Vec2<T>::operator-(const Vec2& vec) const {
  Vec2 result;

  result.x = vec.x - x;
  result.y = vec.y - y;

  return result;
}

template <typename T>
Vec2<T> Vec2<T>::operator*(T a) const {
  Vec2 result;

  result.x = x * a;
  result.y = y * a;

  return result;
}

template <typename T>
Vec2<T> Vec2<T>::operator/(T a) const {
  Vec2 result;

  result.x = x / a;
  result.y = y / a;

  return result;
}

template <typename T>
void Vec2<T>::operator+=(const Vec2& vec) {
  x += vec.x;
  y += vec.y;
}

template <typename T>
void Vec2<T>::operator-=(const Vec2& vec) {
  x -= vec.x;
  y -= vec.y;
}

template <typename T>
void Vec2<T>::operator*=(T a) {
  x *= a;
  y *= a;
}

template <typename T>
void Vec2<T>::operator/=(T a) {
  x /= a;
  y /= a;
}

template <typename T>
void Vec2<T>::add(T x, T y) {
  this->x += x;
  this->y += y;
}

template <typename T>
void Vec2<T>::sub(T x, T y) {
  this->x -= x;
  this->y -= y;
}

template <typename T>
void Vec2<T>::stretch(T s) {
  this->x *= s;
  this->y *= s;
}

template <typename T>
void Vec2<T>::squish(T s) {
  this->x /= s;
  this->y /= s;
}

template <typename T>
std::string Vec2<T>::toString() const {
  return std::to_string(x) + ", " + std::to_string(y);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& v) {
  os << v.x << ", " << v.y;
  return os;
}

typedef Vec2<double> Vec2f;

const Vec2f ErrorVector(std::numeric_limits<double>::min(), std::numeric_limits<double>::min());

#endif
