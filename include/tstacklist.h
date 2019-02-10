#pragma once

#include <iostream>
#include "exception.h"
#include "tlist.h"
using namespace std;

template <class StackListType>
class TStackList : public TList<StackListType>
{
protected:
  int size;
public:
  TStackList<StackListType>(int _size = 10);
  TStackList<StackListType>(TStackList<StackListType> &A);
  ~TStackList();

  void Put(StackListType A);

  StackListType Get();
  int GetMaxSize();
  int GetSize();

  bool IsEmpty();
  bool IsFull();
  void PrintStack();
};

template <class StackListType>
TStackList<StackListType>::TStackList(int _size) : TList<StackListType>()
{
  if ( _size <= 0 )
    throw TException( "Negative size" );
  size = _size;
}

template <class StackListType>
TStackList<StackListType>::TStackList(TStackList<StackListType> &A) : TList<StackListType>(A)
{
  TList<StackListType>::count = A.count;
}

template<class StackListType>
TStackList<StackListType>::~TStackList()
{}

template <class StackListType>
void TStackList<StackListType>::Put(StackListType A)
{
  if ( this->IsFull() )
    throw TException( "StackList is Full" );
  TList<StackListType>::PutStart(A);
}

template <class StackListType>
StackListType TStackList<StackListType>::Get()
{
  if ( this->IsEmpty() )
    throw TException( "StackList is Empty" );
  return TList<StackListType>::GetStart();
}

template <class StackListType>
int TStackList<StackListType>::GetMaxSize()
{
  return size;
}

template<class StackListType>
int TStackList<StackListType>::GetSize()
{
  return TList<StackListType>::count;
}

template <class StackListType>
bool TStackList<StackListType>::IsEmpty()
{
  if ( TList<StackListType>::count == 0 )
    return true;
  return false;
}

template<class StackListType>
bool TStackList<StackListType>::IsFull()
{
  if ( TList<StackListType>::count == size )
    return true;
  return false;
}

template<class StackListType>
void TStackList<StackListType>::PrintStack()
{
  if ( this->IsEmpty() )
    throw TException( "StackList is Empty" );
  TList<StackListType>::PrintList();
}