#include <iostream>
#include <locale.h>

#include "tablesee.h"

using namespace std;

int main()
{
  TTableSee<int> t;
  TString k("key");
  TElement<int> e1(1, k);
  //std::cout << e1;
  //cout << t;
  return 0;
}