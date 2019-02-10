#include <iostream>
#include "tstacklist.h"
#include "time.h"

using namespace std;

int main()
{
  clock_t time_start;
  clock_t total_time;
  for ( unsigned size = 10; size < 1000000; size *= 10 )
  {
    TStackList<int> p1(size);
    for ( unsigned i = 0; i < size-1; i++ )
    {
      p1.Put(i);
    }
    total_time = 0;
    time_start = clock();
    /*p1.Put(1);*/
    p1.Get();
    total_time += clock() - time_start;
    /*cout<< "Size is: " << size << "  Time(put) is: " << total_time <<endl;*/
    cout<< "Size is: " << size << "  Time(get) is: " << total_time <<endl;
  }
  return 0;
}