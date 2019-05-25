#include <iostream>
#include <locale.h>

#include "ttabletree.h"

using namespace std;

int main()
{
  int data;
  int max;
  TTableTree<int> look;
  TElemTree<int> element;
  char memory[100];
  cout << "EXAMPLE: TABLE BY TREE"<< endl;
  cout << "Max count of elements: ";
  cin >> max;
  for (int i = 0; i < max; i++)
  {
    cout << " Key of "<< i + 1 <<" element: ";
    cin >> memory;
    TString key(memory);
    element.SetKey(key);
    cout << " Data of "<< i + 1 <<" element: ";
    cin >> data;
    element.SetData(data);
    look.Add(element);
  }
  cout << endl << look;
  cout << "ADD ELEMENT\n  ";
  cout << "  Key of new element: ";
  cin >> memory;
  TString key1(memory);
  element.SetKey(key1);
  cout << "  Data of new element: ";
  cin >> data;
  element.SetData(data);
  look.Add(element);
  cout << endl << look;
  cout << "DELETE ONE ELEMENT\n  ";
  cout << "  Key of element for delete: ";
  cin >> memory;
  TString key2(memory);
  look.Delete(key2);
  cout << endl << look;
  return 0;
}