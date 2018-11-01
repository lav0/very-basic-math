#pragma once

namespace verybasicmath
{
  class Point
  {
  public:

    Point();
    Point(double, double, double);

    double x() const { return mPoint[0]; }
    double y() const { return mPoint[1]; }
    double z() const { return mPoint[2]; }
    void setX(double x) { mPoint[0] = x; }
    void setY(double y) { mPoint[1] = y; }
    void setZ(double z) { mPoint[2] = z; }

    double operator[](unsigned int index) const { return mPoint[index]; }

  private:
    double mPoint[3] = { 0.0, 0.0, 0.0 };
  };
}
