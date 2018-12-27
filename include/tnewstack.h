#pragma once

#include <iostream>

#include "tstack.h"
#include "exception.h"

template <typename NewStackType>
class TNewStack :public TStack<NewStackType>
{
public:
  TNewStack(int _size = 0, NewStackType* _memory = 0);
  TNewStack(TNewStack <NewStackType> &NS);
  int GetFreeMemory();
  int GetSize();
  int GetTop();
  void SetMemory(int _size, NewStackType* _memory);
  void Put(NewStackType _A);
  NewStackType Get();
};

//--------------------------------------------------------------------------
template <typename NewStackType>
TNewStack<NewStackType>::TNewStack(int _size, NewStackType* _memory)
{
  TStack<NewStackType>::size = _size;
  TStack<NewStackType>::top = 0;

  if (memory != NULL) delete [] memory;
  TStack<NewStackType>::memory = _memory;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
TNewStack<NewStackType>::TNewStack(TNewStack <NewStackType> &NS)
{
  TStack<NewStackType>::size = NS.TStack<NewStackType>::size;
  TStack<NewStackType>::top = NS.TStack<NewStackType>::top;

  if (memory != NULL) delete [] memory;
  TStack<NewStackType>::memory = NS.TStack<NewStackType>::memory;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
int TNewStack<NewStackType>::GetFreeMemory()
{
  return (TStack<NewStackType>::size - TStack<NewStackType>::top);
}
//--------------------------------------------------------------------------
template <typename NewStackType>
int TNewStack<NewStackType>::GetSize()
{
  return TStack<NewStackType>::size;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
int TNewStack<NewStackType>::GetTop()
{
  return TStack<NewStackType>::top;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
void TNewStack<NewStackType>::SetMemory(int _size, NewStackType* _memory)
{
  TStack<NewStackType>::size = _size;
  TStack<NewStackType>::memory = _memory;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
void TNewStack<NewStackType>::Put(NewStackType _A)
{
  TStack<NewStackType>::memory[TStack<NewStackType>::top] = _A;
  TStack<NewStackType>::top++;
}
//--------------------------------------------------------------------------
template <typename NewStackType>
NewStackType TNewStack<NewStackType>::Get()
{
  TStack<NewStackType>::top--;
  return TStack<NewStackType>::memory[TStack<NewStackType>::top];
}