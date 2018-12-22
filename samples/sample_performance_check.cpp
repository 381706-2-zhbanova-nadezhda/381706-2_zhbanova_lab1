#include <iostream>
#include "utmatrix.cpp"
#include "utvector.cpp"
#include "time.h"

using namespace std;

int main()
{
  int max_count = 0;
  cout << "Enter number of checks - ";
  cin  >> max_count;
  clock_t time;
  clock_t average_time;
  for ( unsigned size = 10; size < 100000; size *= 10 )
  {
    TMatrix<int> matrix1(size);
    TMatrix<int> matrix2(size);
    for ( int i = 0; i < size; i++ )
      for ( int j = i; j < size; j++ )
      {
        matrix1[i][j] = i;
        matrix2[i][j] = j;
      }
    average_time = 0;
    for (unsigned count = 0; count < max_count; count++)
    {
      time = clock();
      matrix1 + matrix2;
      average_time += clock() - time;
    }
    average_time /= max_count;
    cout<< "Time is: " <<average_time<<endl;
  }
  return 0;
}