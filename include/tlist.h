#pragma once

#include <iostream>
#include "exception.h"
#include "telement.h"
using namespace std;

template <class ListType>
class TList
{
protected:
  int count;
  TElement<ListType>* start;
public:
  TList();
  TList(TList<ListType> &List);
  ~TList();

  void Put(int _n, ListType elem);
  void PutStart(ListType List);
  void PutEnd(ListType List);

  ListType Get(int _n);
  ListType GetStart();
  ListType GetEnd();

  bool IsFull();
  bool IsEmpty();
  void PrintList();
};

template <class ListType>
TList<ListType>::TList()
{
  count = 0;
  start = 0;
}

template <class ListType>
TList<ListType>::TList(TList<ListType> &List)
{
  count = List.count;
  TElement<ListType> *tmp1 = List.start;
  TElement<ListType> *tmp2;
  if ( List.start == 0 )
    start = 0;
  else
  {
    start = new TElement<ListType>(*List.start);
    tmp2 = start;
      while (tmp1->TElement<ListType>::GetNext() != 0)
      {
        tmp2->TElement<ListType>::SetNext(new TElement<ListType>(*(tmp1->TElement<ListType>::GetNext())));
        tmp1 = tmp1->TElement<ListType>::GetNext();
        tmp2 = tmp2->TElement<ListType>::GetNext();
      }
  }
}

template <class ListType>
TList<ListType>::~TList()
{
  while ( start != 0 )
  {
    TElement<ListType>* temp = start;
    start = start->GetNext();
    delete temp;
  }
}

template<class ListType>
void TList<ListType>::Put(int _n, ListType elem)
{
  if (_n < 1 || _n > count - 1)
    throw TException("Uncurrent index.");
  else
  {
    int i = 0;
    TElement<ListType>* li = start;
    while (i != _n - 1)
    {
      li = li->GetNext();
      i++;
    }
    TElement<ListType>* temp = new TElement<ListType>(elem, li->GetNext());
    li->SetNext(temp);
  }
  count++;
}

template <class ListType>
void TList<ListType>::PutStart(ListType List)
{
  if ( start == 0 )
  {
    TElement<ListType>* temp = new TElement<ListType>(List, 0);
    start = temp;
  }
  else
  {
    TElement<ListType>* temp = new TElement<ListType>(List, start);
    start = temp;
  }
  count++;
}

template <class ListType>
void TList<ListType>::PutEnd(ListType List)
{
  if (IsEmpty())
  {
    start = new TElement<ListType>(List, 0);
  }
  else
  {
    TElement<ListType>* temp = start;
    while ( temp->GetNext() != 0 )
      temp = temp->GetNext();

    temp->SetNext(new TElement <ListType>(List, 0));
  }
  count++;
}

template<class ListType>
ListType TList<ListType>::Get(int _n)
{
  if (IsEmpty() )
    throw TException( "List is empty." );
  if ( _n < 1 || _n > count - 1 )
    throw TException( "Uncurrent index." );
  else
  {
    int i = 0;
    count--;
    TElement<ListType>* li = start;
    TElement<ListType>* di = start->GetNext();
    while ( i != _n - 1 )
    {
      li = di;
      di = di->GetNext();
      i++;
    }
    ListType temp = di->GetElem();
    li->SetNext( di->GetNext() );
    delete di;
    return temp;
  }
}

template <class ListType>
ListType TList<ListType>::GetStart()
{
  if (!IsEmpty())
  {
    ListType temp = start->GetElem();
    start = start->GetNext();
    count--;
    return temp;
  }
  else
    throw TException("Have not any elem");
}

template <class ListType>
ListType TList<ListType>::GetEnd()
{
  if (!IsEmpty())
  {
    TElement<ListType>* temp = start;
    while ((temp->GetNext())->GetNext() != 0)
      temp = temp->GetNext();

    ListType tempE = (temp->GetNext())->GetElem();

    temp->SetNext(0);
    count--;
    return tempE;
  }
  else
    throw TException("Have not any elem");
}

template <class ListType>
bool TList<ListType>::IsFull()
{
  try
  {
    TElement<ListType>* List = new TElement<ListType>();
    if ( List != 0 )
  {
    delete List;
    return true;
  }
  else
    return false;
  }
  catch (...)
  {
    return false;
  }
  return true;
}

template <class ListType>
bool TList<ListType>::IsEmpty()
{
  return ( start == 0 );
}

template<class ListType>
void TList<ListType>::PrintList()
{
  if ( start == 0 )
    throw TException( "List is empty." );
  else
  {
    TElement<ListType>* li = start;
    while ( li->GetNext() != 0 )
    {
      cout << "\t|" << li->GetElem() << "|" << endl;
      li = li->GetNext();
    }
    cout << "\t|" << li->GetElem() << "|" << endl;
  }
}