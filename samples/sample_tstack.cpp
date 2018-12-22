#include <iostream>
#include <locale.h>

#include "tstack.h"

using namespace std;

int main()
{
  try
  {
    int n;
    cout << "Enter stack size:"<< endl;
    cin >> n;
    TStack<char> s1(n);
    char symbol;
    cout << "Enter stack elements:"<< endl;
    for ( int i = 0; i < n; i++ )
    {
      cin >> symbol;
      s1.Put(symbol);
    }
    s1.PrintStack();
    cout << "Remove element from stack:"<< endl;
    s1.Get();
    s1.PrintStack();
    cout << "New stack by Copy constructor:"<< endl;
    TStack<char> s2(s1);
    s2.PrintStack();
  }
  catch (TException exp)
  {
    exp.Show();
  }
  return 0;
}