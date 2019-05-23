#pragma once

#include "tstring.h"
#include <iostream>

using namespace std;

template <typename ElemType>
class TElement
{
protected:
  ElemType data;
  TString key;
public:
  TElement();
  TElement(const ElemType& A, const TString& B);
  TElement(const ElemType& A);
  ~TElement(){}

  TElement& operator=(const TElement<ElemType>& A);
  bool operator==(const TElement<ElemType>& A);
  bool operator!=(const TElement<ElemType>& A);

  ElemType& GetData() { return data; }
  TString& GetKey() { return key; }

  void SetData(const ElemType& A) { data = A; }
  void SetKey(const TString& A) { key = A; }
  template <typename Operator>
  friend ostream& operator<<(ostream& ostr, TElement<Operator>& A);
};
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement() : data(0), key(" ")
{
}
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement(const ElemType& A, const TString& B) : data(A), key(B)
{
}
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement(const ElemType& A) : data(A.data), key(A.key)
{
}
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>& TElement<ElemType>::operator=(const TElement<ElemType>& A)
{
  if (this != &A)
  {
    data = A.data;
    key = A.key;
  }
  return *this;
}
//----------------------------------------------------------------------
template <typename ElemType>
bool TElement<ElemType>::operator==(const TElement<ElemType>& A)
{
  if (data == A.data && key == A.key)
    return true;
  return false;
}
//----------------------------------------------------------------------
template <typename ElemType>
bool TElement<ElemType>::operator!=(const TElement<ElemType>& A)
{
  if (data == A.data && key == A.key)
    return false;
  return true;
}
//----------------------------------------------------------------------
template <typename Operator>
ostream& operator<<(ostream& ostr, TElement<Operator>& A)
{
  ostr << "|" << A.GetKey().GetMemory() << "|";
  ostr << A.GetData() <<"|";
  return ostr;
}