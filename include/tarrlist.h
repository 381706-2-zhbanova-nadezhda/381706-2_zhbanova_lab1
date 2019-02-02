#pragma once

#include <iostream>
#include "exception.h"
#include "tqueue.h"

using namespace std;

template <class ArrListType>
class TArrList
{
private:
  int size;
  int count;
  int start;
  int end;
  int *after;
  int *before;
  ArrListType* memory;
  TQueue <int> nullElem;
public:
  TArrList(int _size = 10);
  TArrList(TArrList<ArrListType> &List);
  ~TArrList();

  void Put(int n, ArrListType elem);
  void PutStart(ArrListType elem);
  void PutEnd(ArrListType elem);

  ArrListType Get(int n);
  ArrListType GetStart();
  ArrListType GetEnd();

  bool IsFull();
  bool IsEmpty();
  void Print();
};
//-----------------------------------------------------------------
template <class ArrListType>
TArrList<ArrListType>::TArrList(int _size) : nullElem(_size)
{
  if ( _size <= 0 )
    throw TException( "False size list." );
  size = _size;
  count = 0;
  start = -1;
  end = -1;
  memory = new ArrListType[size];
  after = new int[size];
  before = new int[size];
  for ( int i = 0; i < size; i++ )
  {
    after[i] = -2;
    before[i] = -2;
    nullElem.Put(i);
  }
}
//-----------------------------------------------------------------
template <class ArrListType>
TArrList<ArrListType>::TArrList(TArrList<ArrListType> &List)
{
  start = List.start;
  end = List.end;
  size = List.size;
  count = List.count;
  memory = new ArrListType[size];
  after = new int[size];
  before = new int[size];
  nullElem = List.nullElem;
  for ( int i = 0; i < size; i++ )
  {
    memory[i] = List.memory[i];
    after[i] = List.after[i];
    before[i] = List.before[i];
  }
}
//-----------------------------------------------------------------
template<class ArrListType>
inline TArrList<ArrListType>::~TArrList()
{
  delete[] memory;
  delete[] after;
  delete[] before;
}
//-----------------------------------------------------------------
template<class ArrListType>
void TArrList<ArrListType>::Put(int n, ArrListType elem)
{
  if (IsFull())
    throw TException( "List is full." );
  if (n < 1 || n > count - 1)
    throw TException( "Uncurrent index." );
  int t = nullElem.Get();
  memory[t] = elem;
  int first = start;
  int second = after[start];
  for ( int i = 0; i < n - 1; i++ )
  {
    first = second;
    second = after[second];
  }
  after[t] = second;
  after[first] = t;

  before[t] = first;
  before[second] = t;
  count++;
}
//-----------------------------------------------------------------
template <class ArrListType>
void TArrList<ArrListType>::PutStart(ArrListType elem)
{
  if ( IsFull() )
    throw TException( "List is full." );
  int t = nullElem.Get();
  memory[t] = elem;
  after[t] = start;
  if ( start != -1 )
    before[start] = t;
  else
    end = t;
  start = t;
  count++;
}
//-----------------------------------------------------------------
template <class ArrListType>
void TArrList<ArrListType>::PutEnd(ArrListType elem)
{
  if ( IsFull() )
    throw TException( "List is full." );
  int t = nullElem.Get();
  memory[t] = elem;
  if ( end != -1 )
    after[end] = t;
  else
  {
    start = t;
    before[t] = -1;
  }
  before[t] = end;
  end = t;
  count++;
}
//-----------------------------------------------------------------
template<class ArrListType>
ArrListType TArrList<ArrListType>::Get(int n)
{
  if ( IsEmpty() )
    throw TException( "List is empty." );
  if ( n < 1 || n > count - 1 )
    throw TException( "Uncurrent index." );
  int t = start;
  for ( int i = 0; i < n; i++ )
    t = after[t];
  after[before[t]] = after[t];
  before[after[t]] = before[t];
  ArrListType temp = memory[t];
  nullElem.Put(t);
  count--;
  return temp;
}
//-----------------------------------------------------------------
template <class ArrListType>
ArrListType TArrList<ArrListType>::GetStart()
{
  if (IsEmpty())
    throw TException( "List is empty." );
  ArrListType elem = memory[start];
  nullElem.Put(start);
  int newstart = after[start];
  after[start] = before[start] = -2;
  if (newstart != -1)
    before[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}
//-----------------------------------------------------------------
template <class ArrListType>
ArrListType TArrList<ArrListType>::GetEnd()
{
  if ( IsEmpty() )
    throw TException( "List is empty." );
  ArrListType elem = memory[end];
  int newfinish = before[end];
  before[end] = after[end] = -2;
  nullElem.Put(end);
  end = newfinish;
  if ( newfinish != -1 )
    after[newfinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}
//-----------------------------------------------------------------
template <class ArrListType>
bool TArrList<ArrListType>::IsFull()
{
  if ( count == size )
    return true;
  return false;
}
//-----------------------------------------------------------------
template <class ArrListType>
bool TArrList<ArrListType>::IsEmpty()
{
  if ( count == 0 )
    return true;
  return false;
}
//-----------------------------------------------------------------
template <class ArrListType>
void TArrList<ArrListType>::Print()
{
  int t = start;
  for ( int i = 0; i < count; i++ )
  {
    cout << memory[t] << " ";
    t = after[t];
  }
}