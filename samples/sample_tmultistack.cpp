#include <iostream>
#include "tmultistack.h"

using namespace std;

int main()
{
  cout << "Creating multistack m1(2,8)" << endl;
  TMStack<int> m1(2, 8);
  cout << "Fill stacks" << endl;

  cout << endl  << "0 stack with elements: '1' '2' '3'" << endl;
  m1.Set(0, 1);
  m1.Set(0, 2);
  m1.Set(0, 3);

  cout << endl << "1 stack with elements: '4' '5' '6' '7'" << endl;
  m1.Set(1, 4);
  m1.Set(1, 5);
  m1.Set(1, 6);
  m1.Set(1, 7);

  cout << endl << " check 1 stack is full" << endl;
  cout << "Use repacking and try to set '8' to 1 stack" << endl;
  m1.Set(1, 8);
  cout << endl << "Get elements from 1 the stack: " << endl;
  cout << m1.Get(1) << endl;
  cout << m1.Get(1) << endl;
  cout << m1.Get(1) << endl;
  cout << m1.Get(1) << endl;
  cout << m1.Get(1) << endl;
  cout << endl << "Get the elements from 0 the stack: " << endl;
  cout << m1.Get(0) << endl;
  cout << m1.Get(0) << endl;
  cout << m1.Get(0) << endl;
  return 0;
}