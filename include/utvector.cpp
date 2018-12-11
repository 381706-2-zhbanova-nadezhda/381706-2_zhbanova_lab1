#include "utvector.h"

template <class VectorType>
TVector<VectorType>::TVector(int s, int si):Size(s),StartIndex(si)
{
  if((s>MAX_VECTOR_SIZE)||(s<=0)) throw 1;
  else if((si>MAX_VECTOR_SIZE)||(si<0)) throw 1;
  else
  pVector = new VectorType [s];
}

template <class VectorType>
TVector<VectorType>::TVector(const TVector<VectorType> &v)
{
  StartIndex=v.StartIndex;
  Size=v.Size;
  delete [] pVector;
  pVector = new VectorType[Size];

  for (int i=0;i<Size;i++) pVector[i]=v.pVector[i];
}

template <class VectorType>
TVector<VectorType>::~TVector()
{
  delete [] pVector;
}

template <class VectorType>
VectorType& TVector<VectorType>::operator[](int pos)
{
  if (pos < StartIndex || pos >= StartIndex + Size) {
    throw 3;
  }
  return pVector[pos-StartIndex];
}

template <class VectorType>
bool TVector<VectorType>::operator==(const TVector &v) const
{
  if(Size!=v.Size || StartIndex!=v.StartIndex) {
    return false;
  }

  for (int i=0;i<Size;i++) {
    if (pVector[i]!=v.pVector[i]) {
      return false;
    }
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
  if(&v!=this){
    StartIndex = v.StartIndex;

    if (Size != v.Size) {
    Size=v.Size;
    delete [] pVector;
    pVector = new VectorType [Size];
    }

    for (int i=0;i<Size;i++) pVector[i]=v.pVector[i];
  }
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const VectorType &val)
{
  for(int i = 0; i < Size; i++)
    pVector[i] += val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const VectorType &val)
{
  for(int i = 0; i < Size; i++)
    pVector[i] -= val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator*(const VectorType &val)
{
  for(int i = 0; i < Size; i++)
    pVector[i] *= val;
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const TVector<VectorType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  } else {
    for(int i = 0; i < Size; i++)
        pVector[i] = pVector[i] + v.pVector[i];
  }

  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const TVector<VectorType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  } else {
    for(int i = 0; i < Size; i++)
        pVector[i] = pVector[i] - v.pVector[i];
  }

  return *this;
}

template <class VectorType>
VectorType TVector<VectorType>::operator*(const TVector<VectorType> &v)
{
  VectorType result;
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  } else {
    for(int i = 0; i < Size; i++)
        result += pVector[i] * v.pVector[i];
  }

  return result;
}