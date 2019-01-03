#include <iostream>
#include <locale.h>

#include "tqueue.h"

using namespace std;

int main()
{
  try
  {
    int n;
    int input;
    cout << "Enter queue size:"<< endl;
    cin >> n;
    TQueue<char> s1(n);
    char symbol;
    cout << "Enter queue elements:"<< endl;
    for ( int i = 0; i < n; i++ )
    {
      cin >> symbol;
      s1.Put(symbol);
    }
    s1.PrintQueue();
    for ( int i = 0; i <= 100; i++)
    {
      cout << "Selection:"<< endl;
      cout << "1.Add an element"<< endl;
      cout << "2.Remove start's element"<< endl;
      cout << "3.Is the queue full or empty?"<< endl;
      cout << "4.Copy the queue"<< endl;
      cout << "5.Exit"<< endl;
      cin >> input;
      switch(input)
      {
        case 1:
        {
          char elem;
          cout << "Enter element:"<< endl;
          cin >> elem;
          if (!s1.IsFull())
          {
            s1.Put(elem);
            s1.PrintQueue();
          }
          else
          {
            cout<<"Queue is full"<<endl;
          }
          break;
        }
        case 2:
        {
          if (!s1.IsEmpty())
          {
            s1.Get();
            s1.PrintQueue();
          }
          else
          {
            cout<<"Queue is empty"<<endl;
          }
          break;
        }
        case 3:
        {
          if ( s1.IsFull() )
            cout << "Full queue"<< endl;
          else if (s1.IsEmpty())
            cout << "Empty queue"<< endl;
          break;
        }
        case 4:
        {
          cout << "New queue by Copy constructor:"<< endl;
          TQueue<char> s2(s1);
          s2.PrintQueue();
          break;
        }
        case 5:
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