#include "task.h"

RightTriangle::RightTriangle() : a(1.0), b(1.0) {}

RightTriangle::RightTriangle(double a, double b) {
  setA(a);
  setB(b);
}

RightTriangle::RightTriangle(const RightTriangle& other)
    : a(other.a), b(other.b) {}

double RightTriangle::getA() const { return a; }

double RightTriangle::getB() const { return b; }

void RightTriangle::setA(double a) {
  if (a <= 0) {
    std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    this->a = 1.0;
  } else {
    this->a = a;
  }
}

void RightTriangle::setB(double b) {
  if (b <= 0) {
    std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    this->b = 1.0;
  } else {
    this->b = b;
  }
}

double RightTriangle::calculateArea() const { return (a * b) / 2.0; }

RightTriangle& RightTriangle::operator++() {
  a *= 2.0;
  b *= 2.0;
  return *this;
}

RightTriangle& RightTriangle::operator--() {
  a /= 2.0;
  b /= 2.0;
  return *this;
}

RightTriangle::operator double() const {
  if (static_cast<bool>(*this)) {
    return calculateArea();
  } else {
    return -1.0;
  }
}

RightTriangle::operator bool() const { return (a > 0 && b > 0); }

bool RightTriangle::operator<=(const RightTriangle& other) const {
  return this->calculateArea() <= other.calculateArea();
}

bool RightTriangle::operator>=(const RightTriangle& other) const {
  return this->calculateArea() >= other.calculateArea();
}

std::ostream& operator<<(std::ostream& out, const RightTriangle& triangle) {
  out << "Треугольник с катетами: a = " << triangle.a << ", b = " << triangle.b;
  return out;
}