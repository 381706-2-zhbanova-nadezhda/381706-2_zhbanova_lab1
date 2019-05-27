#pragma once

#include "tpoint.h"

class TCircle
{
protected:
  TPoint* center;
  double radius;
public:
  TCircle();
  TCircle(const TPoint* A, double rad);
  TCircle(const int _x, const int _y, const double R);
  TCircle(const TCircle& A);
  ~TCircle();
  void SetX(const int param);
  void SetY(const int param);
  void SetRadius(const double rad);
  double GetX() { return center->GetX(); }
  double GetY() { return center->GetY(); }
  double GetRadius() { return radius; }
  void Show();
};
//----------------------------------------------------------------------
TCircle::TCircle() : radius(0)
{
  center = new TPoint(0,0);
}
//----------------------------------------------------------------------
TCircle::TCircle(const TPoint* A, double R)
{
  if (R < 0)
    throw TException("Error");
  center = new TPoint(*A);
  radius = R;
}
//----------------------------------------------------------------------
TCircle::TCircle(const int _x, const int _y, const double R)
{
  if (R < 0)
    throw TException("Error");
  center = new TPoint(_x, _y);
  radius = R;
}
//----------------------------------------------------------------------
TCircle::TCircle(const TCircle& A)
{
  center = new TPoint(*A.center);
  radius = A.radius;
}
//----------------------------------------------------------------------
TCircle::~TCircle()
{
  delete center;
  radius = 0;
}
//----------------------------------------------------------------------
void TCircle::SetX(const int param)
{
  center->SetX(param);
}
//----------------------------------------------------------------------
void TCircle::SetY(const int param)
{
  center->SetY(param);
}
//----------------------------------------------------------------------
void TCircle::SetRadius(const double R)
{
  if (R < 0)
    throw TException("Error");
  radius = R;
}
//----------------------------------------------------------------------
void TCircle::Show()
{
  std::cout << "Center( ";
  center->Show();
  std::cout << " )";
  std::cout << "Radius ( " << radius << " )" << std::endl;
}