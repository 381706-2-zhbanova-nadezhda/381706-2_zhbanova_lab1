#include <iostream>
#include <locale.h>

#include "thashtable.h"

using namespace std;

int main()
{
  int data;
  TElement<int> element;
  char memory[100];
  cout << "EXAMPLE: HASH TABLE"<< endl;
  cout << "Max count of elements: 5";
  THashTable<int> look(3);
  TString string1("str1");
  TString string2("str2");
  TString string3("str3");
  TString string4("str4");
  TString string5("str5");
  TElement<int> element1(1, string1);
  TElement<int> element2(2, string2);
  TElement<int> element3(3, string3);
  TElement<int> element4(4, string4);
  TElement<int> element5(5, string5);
  look.Add(element3);
  look.Add(element1);
  look.Add(element2);
  look.Add(element4);
  look.Add(element5);
  cout << endl << look;
  cout << "ADD ELEMENT\n  ";
  cout << "Key of new element: ";
  cin >> memory;
  TString key1(memory);
  element.SetKey(key1);
  cout << "  Data of new element: ";
  cin >> data;
  element.SetData(data);
  look.Add(element);
  cout << endl << look;
  cout << "DELETE ELEMENT\n  ";
  cout << "  Key of element for delete: ";
  cin >> memory;
  TString key2(memory);
  look.Delete(key2);
  cout << endl << look;
  return 0;
}