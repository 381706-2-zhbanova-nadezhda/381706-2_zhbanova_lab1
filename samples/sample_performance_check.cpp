#include <iostream>
#include "tarrlist.h"
#include "time.h"

using namespace std;

int main()
{
  clock_t time_start;
  clock_t total_time;
  for ( unsigned size = 10; size < 1000000; size *= 10 )
  {
    TArrList<int> Arrlist1(size);
  for ( unsigned i = 0; i < size - 1; i++ )
    {
      Arrlist1.PutStart(i);
    }
    total_time = 0;
    time_start = clock();
    /*Arrlist1.PutEnd(1);*/
    Arrlist1.PutStart(1);
    total_time += clock() - time_start;
    cout<< "Size is: " << size << "  Time(put to the start) is: " << total_time <<endl;
    /*cout<< "Size is: " << size << "  Time(put to the end) is: " << total_time <<endl;*/
  }
  return 0;
}