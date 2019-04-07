#include <iostream>
#include <string>
#include "TText.h"

int main()
{
  TText text(std::string("abc"));
  cout<<text.ToStr()<<endl;
  return 0;
}