#include <iostream>
#include <locale.h>

#include "tlist.h"

using namespace std;

int main()
{
  cout << endl << "Example" << endl;
  cout << "Create empty list:" << endl;
  TList<int> list1;
  cout << endl << "Add 2 to start" << endl;
  list1.PutStart(2);
  list1.PrintList();
  cout << endl <<"Add 1 to start" << endl;
  list1.PutStart(1);
  list1.PrintList();
  cout << endl <<"Add 3 to end" << endl;
  list1.PutEnd(3);
  list1.PrintList();
  cout << endl <<"Add 4 to end" << endl;
  list1.PutEnd(4);
  list1.PrintList();
  cout << endl <<"copy list:" << endl;
  TList<int> list2(list1);
  list1.PrintList();
  cout << endl <<"Get from end: " << list1.GetEnd() << endl;
  list1.PrintList();
  cout << endl <<"Get from start: " << list1.GetStart() << endl;
  list1.PrintList();
  cout << endl <<"Add 6 between elements:" << endl;
  list1.Put(1, 6);
  list1.PrintList();
  cout << endl <<"Add 7 between elements:" << endl;
  list1.Put(1, 7);
  list1.PrintList();
  cout << endl <<"Get 6 from list:" << endl;
  list1.Get(2);
  list1.PrintList();
  cout << endl;
  return 0;
}