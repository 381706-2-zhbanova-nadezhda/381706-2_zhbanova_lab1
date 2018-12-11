#pragma once

#include <iostream>

using namespace std;

#define MAX_VECTOR_SIZE 1000000;


template <class VectorType>
class TVector
{
protected:
  VectorType *pVector;
  int Size;
  int StartIndex;
public:
  TVector(int s = 1, int si = 0);
  TVector(const TVector &v);
  ~TVector();
  int GetSize()      { return Size;       }
  int GetStartIndex(){ return StartIndex; }
  VectorType& operator[](int pos);
  bool operator==(const TVector &v) const;
  bool operator!=(const TVector &v) const;
  TVector& operator=(const TVector &v);


  TVector  operator+(const VectorType &val);
  TVector  operator-(const VectorType &val);
  TVector  operator*(const VectorType &val);


  TVector  operator+(const TVector &v);
  TVector  operator-(const TVector &v);
  VectorType  operator*(const TVector &v);

  // input\output
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};