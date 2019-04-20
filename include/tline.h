#pragma once

#include <cmath> 
#include <iostream>
#include "tpoint.h"

class TLine
{
protected:
  TPoint* A; //first point
  TPoint* B; //second point
public:
  TLine(void);
  TLine(TPoint* _A, TPoint* _B);
  TLine(const TLine& line);
  ~TLine();
  void SetPointA(TPoint* _A);
  void SetPointB(TPoint* _B);
  TPoint* GetPointA();
  TPoint* GetPointB();
  int GetX1();
  int GetY1();
  int GetX2();
  int GetY2();
  void SetX1(int x1);
  void SetY1(int y1);
  void SetX2(int x2);
  void SetY2(int y2);
  double GetLength() const;
  bool operator==(const TLine& line);
  bool operator!=(const TLine& line);
  virtual void Show();
  friend std::ostream &operator<<(std::ostream &ostr, TLine line);
};
//----------------------------------------------------------------------
TLine::TLine(void)
{
  A = new TPoint;
  B = new TPoint;
}
//----------------------------------------------------------------------
TLine::TLine(TPoint* _A, TPoint* _B)
{
  A = new TPoint(*_A);
  B = new TPoint(*_B);
}
//----------------------------------------------------------------------
TLine::TLine(const TLine& line)
{
  A = new TPoint(*line.A);
  B = new TPoint(*line.B);
}
//----------------------------------------------------------------------
TLine::~TLine()
{
  delete A;
  delete B;
}
//----------------------------------------------------------------------
void TLine::SetPointA(TPoint* _A)
{
  delete A;
  A = new TPoint(*_A);
}
//----------------------------------------------------------------------
void TLine::SetPointB(TPoint* _B)
{
  delete B;
  B = new TPoint(*_B);
}
//----------------------------------------------------------------------
TPoint* TLine::GetPointA()
{
  return A;
}
//----------------------------------------------------------------------
TPoint* TLine::GetPointB()
{
  return B;
}
//----------------------------------------------------------------------
int TLine::GetX1()
{
  return A->GetX();
}
//----------------------------------------------------------------------
int TLine::GetY1()
{
  return A->GetY();
}
//----------------------------------------------------------------------
int TLine::GetX2()
{
  return B->GetX();
}
//----------------------------------------------------------------------
int TLine::GetY2()
{
  return B->GetY();
}
//----------------------------------------------------------------------
void TLine::SetX1(int x1)
{
  A->SetX(x1);
}
//----------------------------------------------------------------------
void TLine::SetY1(int y1)
{
  A->SetY(y1);
}
//----------------------------------------------------------------------
void TLine::SetX2(int x2)
{
  B->SetX(x2);
}
//----------------------------------------------------------------------
void TLine::SetY2(int y2)
{
  B->SetY(y2);
}
//----------------------------------------------------------------------
double TLine::GetLength() const
{
  //Length = √(X²+Y²) = √((X2-X1)²+(Y2-Y1)²)
  double first = B->GetX() - A->GetX();
  double second = B->GetY()-A->GetY();
  double res = sqrt(pow(first,2)+pow(second,2));
  return res;
}
//----------------------------------------------------------------------
bool TLine::operator==(const TLine& line)
{
  if(line.GetLength() == this->GetLength())
    return true;
  else
    return false;
}
//----------------------------------------------------------------------
bool TLine::operator!=(const TLine& line)
{
  if(line.GetLength() != this->GetLength())
    return true;
  else
    return false;
}
//----------------------------------------------------------------------
void TLine::Show()
{
  std::cout <<"Line("<< *A <<","<< *B <<")";
}
//----------------------------------------------------------------------
std::ostream &operator<<(std::ostream &ostr, TLine line)
{
  ostr << "Line(" << *line.A << "," << *line.B <<")";
  return ostr;
}