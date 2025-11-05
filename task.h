#ifndef task_h
#define task_h

#include <iostream>

class RightTriangle {
 public:
  RightTriangle();
  RightTriangle(double a, double b);
  RightTriangle(const RightTriangle& other);

  double getA() const;
  double getB() const;
  void setA(double a);
  void setB(double b);

  double calculateArea() const;

  RightTriangle& operator++();
  RightTriangle& operator--();

  explicit operator double() const;
  operator bool() const;

  bool operator<=(const RightTriangle& other) const;
  bool operator>=(const RightTriangle& other) const;

  friend std::ostream& operator<<(std::ostream& out, const RightTriangle& triangle);

 private:
  double a;
  double b;
};

#endif