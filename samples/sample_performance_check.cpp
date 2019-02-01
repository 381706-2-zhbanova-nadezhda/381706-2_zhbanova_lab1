#include <iostream>
#include "time.h"
#include "tmultistack.h"

using namespace std;

int main()
{
  unsigned max_count = 0;
  cout << "Enter number of checks - ";
  cin  >> max_count;
  clock_t time;
  clock_t average_time;
  for ( unsigned size = 10; size < 100000; size *= 10 )
  {
    TMStack <int> m1(2, size);
    TMStack <int> m2(2, size);
    for ( unsigned i = 0; i < size; i++ )
    {
      m1.Set(1, i);
    }
    average_time = 0;
    for (unsigned count = 0; count < max_count; count++)
    {
      time = clock();
      m1 = m2;
      average_time += clock() - time;
    }
    average_time /= max_count;
    cout<< "Time is: " <<average_time<<endl;
  }
  return 0;
}