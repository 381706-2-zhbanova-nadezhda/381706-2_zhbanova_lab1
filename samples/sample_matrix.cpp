#include <iostream>
#include "utmatrix.cpp"
#include "utvector.cpp"

int main()
{
  TMatrix<int> a(5), b(5), c(5), d(5);
  int i, j;
  std::cout<<"Matrix addition example"<<std::endl;

  for ( i = 0; i < 5; i++ )
    for ( j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = ( i * 10 + j ) * 100;
    }

  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;

  std::cout<<"Matrix division example"<<std::endl;
  d = a*a;
  cout << "Matrix d = a*a" << endl << d << endl;
  return 0;
}
