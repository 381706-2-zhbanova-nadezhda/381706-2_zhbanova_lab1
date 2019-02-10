#include <iostream>
#include <locale.h>

#include "tstacklist.h"

using namespace std;

int main()
{
  try
  {
    int n;
    cout << "Enter stacklist size:"<< endl;
    cin >> n;
    TStackList<char> s1(n);
    char symbol;
    cout << "Enter stacklist elements:"<< endl;
    for ( int i = 0; i < n; i++ )
    {
      cin >> symbol;
      s1.Put(symbol);
    }
    s1.PrintStack();
    cout << "Remove element from stacklist:"<< endl;
    s1.Get();
    s1.PrintStack();
    cout << "New stacklist by Copy constructor:"<< endl;
    TStackList<char> s2(s1);
    s2.PrintStack();
  }
  catch (TException exp)
  {
    exp.Show();
  }
  return 0;
}