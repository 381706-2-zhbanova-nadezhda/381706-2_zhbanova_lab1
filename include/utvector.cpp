#include "utvector.h"

template <class VectorType>
TVector<VectorType>::TVector(int s, int si):Size(s),StartIndex(si)
{
  if((s>MAX_VECTOR_SIZE)||(s<0)) throw 1;
  else if((si>MAX_VECTOR_SIZE)||(si<0)) throw 1;
  else
  pVector = new VectorType [s];
}

template <class VectorType>
TVector<VectorType>::TVector(const TVector<VectorType> &v)
{
  Size=v.Size;
  StartIndex=v.StartIndex;
  pVector = new VectorType[Size];
  for (int i=0;i<Size;i++){pVector[i]=v.pVector[i];}
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
  if(Size!=v.Size)return false;
  else if(StartIndex!=v.StartIndex) return false;
  else {
    for (int i=0;i<Size;i++){
      if (pVector[i]!=v.pVector[i]){
        return false;
      }
    }

  return true;
  }
}

template <class VectorType>
bool TVector<VectorType>::operator!=(const TVector &v) const
{
  if(Size!=v.Size)return true;
  else if(StartIndex!=v.StartIndex) return true;
  else {
    for (int i=0;i<Size;i++){
      if (pVector[i]!=v.pVector[i]){
        return true;
      }
    }

  return false;
  }
}

template <class VectorType>
TVector<VectorType>& TVector<VectorType>::operator=(const TVector &v)
{
  if(&v!=this){
    Size=v.Size;
    StartIndex = v.StartIndex;

    delete [] pVector;
    pVector = new VectorType [Size];

    for (int i=0;i<Size;i++) pVector[i]=v.pVector[i];
  }
  return *this;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const VectorType &val)
{
  TVector <VectorType> buf(Size,StartIndex);

  for(int i=0;i<Size;i++){
    buf.pVector[i]=pVector[i]+val;}

  return buf;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const VectorType &val)
{
  TVector <VectorType> buf(Size,StartIndex);

  for(int i=0;i<Size;i++){
    buf.pVector[i]=pVector[i]-val;}

  return buf;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator*(const VectorType &val)
{
  TVector <VectorType> buf(Size,StartIndex);

  for(int i=0;i<Size;i++) buf.pVector[i]=pVector[i]*val;

  return buf;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator+(const TVector<VectorType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  }

  TVector<VectorType> temp(Size, StartIndex);

  for (int i = 0; i < Size; i++) {
    temp.pVector[i] = pVector[i] + v.pVector[i];
  }

  return temp;
}

template <class VectorType>
TVector<VectorType> TVector<VectorType>::operator-(const TVector<VectorType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  }

  TVector<VectorType> temp(Size, StartIndex);

  for (int i = 0; i < Size; i++) {
    temp.pVector[i] = pVector[i] - v.pVector[i];
  }

  return temp;
}

template <class VectorType>
VectorType TVector<VectorType>::operator*(const TVector<VectorType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw 4;
  }

  VectorType skalar = pVector[0]*v.pVector[0];
  for (int i=1;i<Size;i++){
    skalar+=(pVector[i]*v.pVector[i]);
  }
  return skalar;
}