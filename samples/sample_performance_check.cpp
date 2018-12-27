#include <iostream>
#include "time.h"
#include "tnewstack.h"

using namespace std;

int main()
{
  char * mem = new char[100];
  TNewStack<char>  ns(100,mem);
  cout << "Dummy sample\n";
  return 0;
}