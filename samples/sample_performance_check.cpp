#include <iostream>
#include "tlist.h"
#include "time.h"

using namespace std;

int main()
{
  clock_t time_start;
  clock_t total_time;
  for ( unsigned size = 10; size < 1000000; size *= 10 )
  {
    TList<int> list1;
  for ( unsigned i = 0; i < size; i++ )
    {
      list1.PutStart(i);
    }
    total_time = 0;
    time_start = clock();
    /*list1.PutEnd(1);*/
    list1.PutStart(1);
    total_time += clock() - time_start;
    cout<< "Size is: " << size << "  Time(put to the start) is: " << total_time <<endl;
    /*cout<< "Size is: " << size << "  Time(put to the end) is: " << total_time <<endl;*/
  }
  return 0;
}
