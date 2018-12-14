#include "utvector.h"

template <class VectorType>
TVector<VectorType>::TVector(int s, int si):size(s),startIndex(si)
{
  if ( (s > MAX_VECTOR_SIZE)||(s <= 0) )
    throw 1;
  else if ( (si > MAX_VECTOR_SIZE)||(si < 0) )
    throw 1;
  else
    pVector = new VectorType [s];
}

template <class VectorType>
TVector<VectorType>::TVector(const TVector<VectorType> &v)
{
  startIndex=v.startIndex;
  size=v.size;
  pVector = new VectorType[size];
  for ( int i = 0; i < size; i++ )
    pVector[i]=v.pVector[i];
}

template <class VectorType>
TVector<VectorType>::~TVector()
{
  delete [] pVector;
}

template <class VectorType>
VectorType& TVector<VectorType>::operator[](int pos)
{
  if ( pos < startIndex || pos >= startIndex + size )
    throw 3;
  return pVector[pos-startIndex];
}

template <class VectorType>
bool TVector<VectorType>::operator==(const TVector &v) const
{
  if ( size!=v.size || startIndex!=v.startIndex )
    return false;
  for ( int i = 0; i < size; i++ )
  {
    if ( pVector[i] != v.pVector[i] )
      return false;
  }
  return true;
}

template <class VectorType>
bool TVector<VectorType>::operator!=(const TVector &v) const
{
  return !TVector<VectorType>::operator==(v);
}

template <class VectorType>
TVector<VectorType>& TVector<VectorType>::operator=(const TVector &v)
{
  if( &v != this )
  {
    startIndex = v.startIndex;
    if ( size != v.size )
    {
      size=v.size;
      delete [] pVector;
      pVector = new VectorType [size];
    }
    for ( int i = 0; i < size; i++ )
      pVector[i] = v.pVector[i];
  }
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const VectorType &val)
{
  for ( int i = 0; i < size; i++ )
    pVector[i] += val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const VectorType &val)
{
  for ( int i = 0; i < size; i++ )
    pVector[i] -= val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator*(const VectorType &val)
{
  for ( int i = 0; i < size; i++ )
    pVector[i] *= val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const TVector<VectorType> &v)
{
  TVector tmp (*this);
  if ( size != v.size || startIndex != v.startIndex )
    throw 4;
  else
  {
    for ( int i = 0; i < size; i++ )
        tmp.pVector[i] = pVector[i] + v.pVector[i];
  }
  return tmp;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const TVector<VectorType> &v)
{
  TVector tmp (*this);
  if ( size != v.size || startIndex != v.startIndex )
    throw 4;
  else
  {
    for ( int i = 0; i < size; i++ )
        tmp.pVector[i] = pVector[i] - v.pVector[i];
  }
  return tmp;
}

template <class VectorType>
VectorType TVector<VectorType>::operator*(const TVector<VectorType> &v)
{
  VectorType result = 0;
  if ( size != v.size || startIndex != v.startIndex )
    throw 4;
  else
  {
    for ( int i = 0; i < size; i++ )
        result += pVector[i] * v.pVector[i];
  }
  return result;
}