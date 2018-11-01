#include "Matrix.h"

using namespace verybasicmath;

verybasicmath::Matrix::Matrix()
{
  toIdentity();
}

verybasicmath::Matrix::Matrix(const double mat[4][4])
{
  for (unsigned i = 0; i<4; i++)
    for (unsigned j = 0; j<4; j++)
      mMat[i][j] = mat[i][j];
}

verybasicmath::Matrix::Matrix(const DHConvention & dh)
{
  toIdentity();

  auto ct = std::cos(dh.get_tetta());
  auto st = std::sin(dh.get_tetta());
  auto ca = std::cos(dh.get_alfa());
  auto sa = std::sin(dh.get_alfa());

  mMat[0][0] = ct;  mMat[0][1] = -st * ca; mMat[0][2] =  st * sa;
  mMat[1][0] = st;  mMat[1][1] =  ct * ca; mMat[1][2] = -ct * sa;
                    mMat[2][1] = sa;       mMat[2][2] = ca;
  
  mMat[0][3] = ct * dh.get_a();
  mMat[1][3] = st * dh.get_a();
  mMat[2][3] = dh.get_d();
}

Point verybasicmath::Matrix::operator*(const Point& pt) const
{
  auto x = mMat[0][0] * pt[0] + mMat[0][1] * pt[1] + mMat[0][2] * pt[2] + mMat[0][3];
  auto y = mMat[1][0] * pt[0] + mMat[1][1] * pt[1] + mMat[1][2] * pt[2] + mMat[1][3];
  auto z = mMat[2][0] * pt[0] + mMat[2][1] * pt[1] + mMat[2][2] * pt[2] + mMat[2][3];
  return Point(x,y,z);
}

Matrix verybasicmath::Matrix::operator*(const Matrix & other) const
{
  Matrix ret;
  for (unsigned int i = 0; i<4; ++i)
  {
    for (unsigned int j = 0; j<4; ++j)
    {
      ret.mMat[i][j] = 0;
      for (unsigned k = 0; k<4; ++k)
        ret.mMat[i][j] += mMat[i][k] * other.mMat[k][j];
    }
  }
  return ret;
}

double verybasicmath::Matrix::operator() (unsigned int i, unsigned int j) const
{
  return mMat[i][j];
}

void verybasicmath::Matrix::toIdentity()
{
  for (unsigned i = 0; i<4; ++i)
  {
    for (unsigned j = 0; j<4; ++j)
    {
      if (i == j)
        mMat[i][j] = 1;
      else
        mMat[i][j] = 0;
    }
  }
}
