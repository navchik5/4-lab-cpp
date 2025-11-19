#include "task.h"

RightTriangle::RightTriangle() : a_(1.0), b_(1.0) {}

RightTriangle::RightTriangle(double a, double b) {
  setA(a);
  setB(b);
}

RightTriangle::RightTriangle(const RightTriangle& other)
    : a_(other.a_), b_(other.b_) {}

double RightTriangle::getA() const { return a_; }

double RightTriangle::getB() const { return b_; }

void RightTriangle::setA(double a) {
  if (a <= 0) {
    std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    this->a_ = 1.0;
  } else {
    this->a_ = a;
  }
}

void RightTriangle::setB(double b) {
  if (b <= 0) {
    std::cout << "Ошибка: катет должен быть положительным числом!" << std::endl;
    this->b_ = 1.0;
  } else {
    this->b_ = b;
  }
}

double RightTriangle::calculateArea() const { return (a_ * b_) / 2.0; }

RightTriangle& RightTriangle::operator++() {
  a_ *= 2.0;
  b_ *= 2.0;
  return *this;
}

RightTriangle& RightTriangle::operator--() {
  a_ /= 2.0;
  b_ /= 2.0;
  return *this;
}

RightTriangle::operator double() const {
  if (a_ > 0 && b_ > 0) {  
    return calculateArea();
  } else {
    return -1.0;  
  }
}

RightTriangle::operator bool() const {
  return (a_ > 0 && b_ > 0);  
}

bool RightTriangle::operator<=(const RightTriangle& other) const {
  return this->calculateArea() <= other.calculateArea();
}

bool RightTriangle::operator>=(const RightTriangle& other) const {
  return this->calculateArea() >= other.calculateArea();
}

std::ostream& operator<<(std::ostream& out, const RightTriangle& triangle) {
  out << "Треугольник с катетами: a = " << triangle.a_ << ", b = " << triangle.b_;
  return out;
}
