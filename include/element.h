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

  ElemType& GetData();
  TString& GetKey();

  void SetData(const ElemType& A);
  void SetKey(const TString& A);
  template <typename Operator>
  friend ostream& operator<<(ostream& out, TElement<Operator>& A);
};
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement()
{
  key = " ";
  data = 0;
}
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement(const ElemType& A, const TString& B)
{
  data = A;
  key = B;
}
//----------------------------------------------------------------------
template <typename ElemType>
TElement<ElemType>::TElement(const ElemType& A)
{
  data = A.data;
  key = B.key;
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
template <typename ElemType>
ElemType& TElement<ElemType>::GetData()
{
  return data;
}
//----------------------------------------------------------------------
template <typename ElemType>
TString& TElement<ElemType>::GetKey()
{
  return key;
}
//----------------------------------------------------------------------
template <typename ElemType>
void TElement<ElemType>::SetData(const ElemType& A)
{
  data = A;
}
//----------------------------------------------------------------------
template <typename ElemType>
void TElement<ElemType>::SetKey(const TString& A)
{
  key = A;
}
//----------------------------------------------------------------------
template <typename Operator>
ostream& operator<<(ostream& ostr, TElement<Operator>& A)
{
  ostr << "|" << A.GetKey().GetMemory() << "|";
  ostr << A.GetData() <<"|";
  return ostr;
}