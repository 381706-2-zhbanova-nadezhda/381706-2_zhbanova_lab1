#include <iostream>
#include <locale.h>

#include "tstack.h"

using namespace std;

int main()
{
  int n;
  cout << "Enter stack size\n";
  do
    cin >> n; while (n < 0);
  TStack<char> symbolStack(n);
  char symbol;
  cout << "Enter stack elements\n";
  for (int i = 0; i < n; i++)
  {
    cin >> symbol;
    symbolStack.Put(symbol);
  }

  cout << "\n";

  symbolStack.PrintStack();

  cout << "\n\nRemove element from stack\n";
  symbolStack.Get();

  symbolStack.PrintStack();

  TStack<char> newOne(symbolStack);

  cout << "\n\nCopy constructor\n";
  newOne.PrintStack();

  return 0;
}