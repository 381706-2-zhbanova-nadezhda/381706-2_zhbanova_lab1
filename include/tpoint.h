#pragma once

#include <iostream>
#include "exception.h"

class TPoint
{
protected:
  int x, y;
public:
  TPoint(int _x = 0, int _y = 0);
  TPoint(const TPoint& A);
  ~TPoint();
  void SetX(int _x);
  void SetY(int _y);
  int GetX();
  int GetY();
  bool operator==(const TPoint& A);
  bool operator!=(const TPoint& A);
  virtual void Show();
  friend std::ostream &operator<<(std::ostream &ostr, TPoint point);
};
//----------------------------------------------------------------------
TPoint::TPoint(int _x, int _y)
{
  x = _x;
  y = _y;
}
//----------------------------------------------------------------------
TPoint::TPoint(const TPoint& A)
{
  x = A.x;
  y = A.y;
}
//----------------------------------------------------------------------
TPoint::~TPoint()
{
  x = 0;
  y = 0;
}
//----------------------------------------------------------------------
void TPoint::SetX(int _x)
{
  x = _x;
}
//----------------------------------------------------------------------
void TPoint::SetY(int _y)
{
  y = _y;
}
//----------------------------------------------------------------------
int TPoint::GetX()
{
  return x;
}
//----------------------------------------------------------------------
int TPoint::GetY()
{
  return y;
}
//----------------------------------------------------------------------
bool TPoint::operator==(const TPoint& A)
{
  if ((x == A.x) && (y == A.y))
    return true;
  else
    return false;
}
//----------------------------------------------------------------------
bool TPoint::operator!=(const TPoint& A)
{
  if ((x == A.x) && (y == A.y))
    return false;
  else
    return true;
}
//----------------------------------------------------------------------
void TPoint::Show()
{
  std::cout << "Point(" << x << ","<< y <<")\n";
}
//----------------------------------------------------------------------
std::ostream &operator<<(std::ostream &ostr, TPoint point)
{
  ostr << "Point(" << point.x << ", " << point.y <<")\n";
  return ostr;
}