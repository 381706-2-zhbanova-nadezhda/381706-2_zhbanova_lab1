#include "utmatrix.h"

template <class MatrixType>
TMatrix<MatrixType>::TMatrix(int s): TVector<TVector<MatrixType> >(s)
{
  if ( s > MAX_MATRIX_SIZE )
    throw 5;

  for ( int i = 0; i < s; i++ )
    this -> pVector[i] = TVector<MatrixType>(s - i, i);
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

template <class MatrixType>
TMatrix<MatrixType> TMatrix<MatrixType>::operator*(const TMatrix<MatrixType> &mt)
{
  if ( this -> size != mt.size )
    throw 5;
  TMatrix<MatrixType> buf ( this -> size );
  for ( int row = 0; row < this -> size; row++ )
    for ( int col = row; col < this -> size; col++ )
    {
      buf.pVector[row][col] = 0;
      for ( int inner = row; inner <= col; inner++ )
        buf.pVector[row][col] += this->pVector[row][inner] * mt.pVector[inner][col];
    }
  return buf;
}

template <class MatrixType>
TMatrix<MatrixType> TMatrix<MatrixType>::inverse_matrix() const
{
  TMatrix<MatrixType> buf( this -> size );
  for ( int i = 0; i < this->size; i++ )
    for ( int j = i; j <this->size; j++ )
    {
      if ( i == j )
        buf.pVector[i][j]=1;
      else
        buf.pVector[i][j]=0;
    }

  for ( int i = this -> size - 1; i >= 0; i-- )
  {
    for( int j = i-1; j >= 0; j-- )
    {
      for ( int inv = i; inv < this -> size; inv++ )
        buf.pVector[j][inv] -= buf.pVector[i][inv] * this->pVector[j][i] / this->pVector[i][i];
    }
  }

    for ( int i = 0; i < this -> size; i++ )
      for( int j = i; j < this -> size; j++ )
      {
        buf.pVector[i][j] /= this -> pVector[i][i];
      }
  return buf;
}

template <class MatrixType>
TMatrix<MatrixType> TMatrix<MatrixType>::operator/(const TMatrix<MatrixType> &mt)
{
  if ( this -> size != mt.size )
    throw 5;
  TMatrix<MatrixType> buf (*this);
  TMatrix<MatrixType> buf2 ();
  buf = buf * mt.inverse_matrix();
  return buf;
}