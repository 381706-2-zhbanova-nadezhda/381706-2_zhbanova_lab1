#include <iostream>
#include "tqueue.h"
#include "time.h"

using namespace std;

int main()
{
  unsigned max_count = 0;
  cout << "Enter number of checks - ";
  cin  >> max_count;
  clock_t time;
  clock_t average_time;
  for ( unsigned size = 10; size < 1000000; size *= 10 )
  {
    TQueue<int> s1(size);
    TQueue<int> s2(size);
    for ( unsigned i = 0; i < size; i++ )
  {
        s1.Put(i);
    }
    average_time = 0;
    for (unsigned count = 0; count < max_count; count++)
    {
      time = clock();
      s1 = s2;
      average_time += clock() - time;
    }
    average_time /= max_count;
    cout<< "Time is: " <<average_time<<endl;
  }
  return 0;
}