#pragma once
#include <cmath>
#include "Constants.h"
#include "Point.h"

namespace verybasicmath {
  struct Matrix
  {
    Matrix();
    Matrix(const double[4][4]);

    Point operator*(const Point&) const;
    Matrix operator*(const Matrix&) const;

    double operator() (unsigned int i, unsigned int j) const;

    void toIdentity();
  private:
    double mMat[4][4];
  };
}
