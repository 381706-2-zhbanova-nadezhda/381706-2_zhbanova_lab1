#include <iostream>
#include <locale.h>

#include "ttablesort.h"

using namespace std;

int main()
{
  int data;
  int num;
  TElement<int> element;
  char memory[100];
  cout << "EXAMPLE: SORT TABLE"<< endl;
  cout << "Max count of elements: 6";
  TTableSee<int> look(3);
  TString string1("str1");
  TString string2("str2");
  TString string3("str3");
  TString string4("str4");
  TString string7("str7");
  TString string6("str6");
  TElement<int> element1(1, string1);
  TElement<int> element2(2, string2);
  TElement<int> element3(3, string3);
  TElement<int> element4(4, string4);
  TElement<int> element7(7, string7);
  TElement<int> element6(6, string6);
  look.Add(element3);
  look.Add(element1);
  look.Add(element2);
  look.Add(element4);
  look.Add(element7);
  look.Add(element6);
  cout << endl << look;
  cout << "SORT OUR TABLE\n";
  cout << "  1.INSERT_SORT \n  2.SELECTION_SORT \n  3.QUICK_SORT \n";
  cout << "Number of Sorting: ";
  cin >> num;
  TSortTable<int> sort(look, num);
  cout << endl << sort;
  cout << "ADD ELEMENT\n  ";
  cout << "Key of new element: ";
  cin >> memory;
  TString key1(memory);
  element.SetKey(key1);
  cout << "  Data of new element: ";
  cin >> data;
  element.SetData(data);
  sort.Add(element);
  cout << endl << sort;
  cout << "DELETE ELEMENT\n  ";
  cout << "  Key of element for delete: ";
  cin >> memory;
  TString key2(memory);
  sort.Delete(key2);
  cout << endl << sort;
  return 0;
}