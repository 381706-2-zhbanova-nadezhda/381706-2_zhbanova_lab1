#pragma once

#include <iostream>

#include "utvector.h"

using namespace std;

#define MAX_MATRIX_SIZE 10000

template <typename MatrixType>
class TMatrix : public TVector<TVector<MatrixType> >
{
  TMatrix inverse_matrix() const;
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);
  TMatrix(const TVector<TVector<MatrixType> > &mt);
  bool operator==(const TMatrix &mt) const;
  bool operator!=(const TMatrix &mt) const;
  TMatrix& operator= (const TMatrix &mt);
  TMatrix  operator+ (const TMatrix &mt);
  TMatrix  operator- (const TMatrix &mt);
  TMatrix  operator* (const TMatrix &mt);
  TMatrix  operator/ (const TMatrix &mt);

  // input\output
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for ( int i = 0; i < mt.size; i++ )
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for ( int i = 0; i < mt.size; i++ ) {
      for ( int j = 0; j<  i; j++ )
        out << "0 ";
      out << mt.pVector[i] << endl;
    }
    return out;
  }
};
