#include <iostream>
#include <locale.h>

#include "tarrlist.h"

using namespace std;

int main()
{
  try
  {
    int size;
    int input;
    cout << "Enter size of list: ";
    cin >> size;
    TArrList<int> Arrlist(size);
    for ( int i = 0; i <= 100; i++ )
    {
    cout << endl << "Selection:" << endl;
    cout << "1.Put to the start " << endl;
    cout << "2.Put to the end " << endl;
    cout << "3.Get from the start"<< endl;
    cout << "4.Get from the end"<< endl;
    cout << "5.Copy the List"<< endl;
    cout << "6.Exit"<< endl;
    cin >> input;
    switch ( input )
    {
      case 1:
      {
      int elem;
      cout << "Enter element:";
      cin >> elem;
      if ( !Arrlist.IsFull() )
      {
        Arrlist.PutStart(elem);
        cout << endl << "List: "<< endl;
        Arrlist.Print();
      }
      else
        cout<<"List is full"<<endl;
      break;
      }
      case 2:
      {
      int elem;
      cout << "Enter element:";
      cin >> elem;
      if ( !Arrlist.IsFull() )
      {
        Arrlist.PutEnd(elem);
        cout << endl << "List: "<< endl;
        Arrlist.Print();
      }
      else
        cout<<"List is full"<<endl;
      break;
      }
      case 3:
      {
      if( !Arrlist.IsEmpty() )
      {
        Arrlist.GetStart();
        cout << endl << "List: "<< endl;
        Arrlist.Print();
      }
      else
        cout<<"List is empty"<<endl;
      break;
      }
      case 4:
      {
      if( !Arrlist.IsEmpty() )
      {
        Arrlist.GetEnd();
        cout << endl << "List: "<< endl;
        Arrlist.Print();
      }
      else
        cout<<"List is empty"<<endl;
      break;
      }
      case 5:
      {
      cout << "New list by Copy constructor:"<< endl;
      TArrList<int> Arrlist2(Arrlist);
      cout << endl << "List: "<< endl;
      Arrlist2.Print();
      break;
      }
      case 6:
      {
      return 0;
      }
      default:
      cout << "Invalid Input!"<< endl;
    }
    }
  }
catch (TException exp)
{
  exp.Show();
}
  return 0;
}