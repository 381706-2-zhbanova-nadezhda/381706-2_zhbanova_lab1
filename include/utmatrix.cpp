#include "utmatrix.h"

template <class MatrixType>
TMatrix<MatrixType>::TMatrix(int s): TVector<TVector<MatrixType> >(s)
{
  if (s > MAX_MATRIX_SIZE) {
    throw 5;
  }

  for (int i = 0; i < s; i++) {
    this -> pVector[i] = TVector<MatrixType>(s - i, i);
  }
}

template <class MatrixType>
TMatrix<MatrixType>::TMatrix(const TMatrix<MatrixType> &mt):
  TVector<TVector<MatrixType> >(mt) {}

template <class MatrixType>
TMatrix<MatrixType>::TMatrix(const TVector<TVector<MatrixType> > &mt):
  TVector<TVector<MatrixType> >(mt) {}

template <class MatrixType>
bool TMatrix<MatrixType>::operator==(const TMatrix<MatrixType> &mt) const
{
  return TVector<TVector<MatrixType> >::operator==(mt);
}

template <class MatrixType>
bool TMatrix<MatrixType>::operator!=(const TMatrix<MatrixType> &mt) const
{
  return TVector<TVector<MatrixType> >::operator!=(mt);
}

template <class MatrixType>
TMatrix<MatrixType>& TMatrix<MatrixType>::operator=(const TMatrix<MatrixType> &mt)
{
  TVector<TVector<MatrixType> >::operator=(mt);
  return *this;
}

template <class MatrixType>
TMatrix<MatrixType> TMatrix<MatrixType>::operator+(const TMatrix<MatrixType> &mt)
{
  return TVector<TVector<MatrixType> >::operator+(mt);
}

template <class MatrixType>
TMatrix<MatrixType> TMatrix<MatrixType>::operator-(const TMatrix<MatrixType> &mt)
{
  return TVector<TVector<MatrixType> >::operator-(mt);
}