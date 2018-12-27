#pragma once

#include "exception.h"
#include "tnewstack.h"

template <typename MultiStackType>
class TMStack
{
protected:
  int size;
  MultiStackType* memory;
  int n;
  TNewStack<MultiStackType>** newS;
  int GetFreeMemory();
  void Repack(int k);

public:
  TMStack(int _n, int _size);
  TMStack(TMStack<MultiStackType> &A);

  int GetSize()
  {
    return size;
  }

  MultiStackType Get(int _n);

  void Set(int _n, MultiStackType p);

  bool IsFull(int _n);
  bool IsEmpty(int _n);
};
//--------------------------------------------------------------------------
template <typename MultiStackType>
TMStack<MultiStackType> ::TMStack(int _n, int _size)
{
  if (_n <= 0 || _size <= 0)
      throw TException ("Negative leight.");

  n = _n;
  size = _size;

  newS = new TNewStack<MultiStackType> *[n];
  memory = new MultiStackType[size];

  int el_size = 0;
  for (int i = 0; i < n; i++)
  {
    el_size = size / n;
    if (i == n -1) el_size += size % n;
    newS[i] = new TNewStack<MultiStackType>(el_size, &memory[i*size/n]);
  }
}
//--------------------------------------------------------------------------
template <typename MultiStackType>
TMStack<MultiStackType> ::TMStack(TMStack &A)
{
  size = A.size;
  n = A.n;

  memory = new MultiStackType[size];
  newS = new TNewStack<MultiStackType> *[n];

  for (int i = 0; i < size; i++)
    memory[i] = A.memory[i];

  int* smth = new int[n];

  for (int i = 0; i < n; i++)
    smth[i] = A.newS[i]->TNewStack<MultiStackType>::GetSize();

  int countingSize = 0;
  newS[0] = new TNewStack<MultiStackType>(*(A.newS[0]));
  newS[0]->TNewStack<MultiStackType>::SetMas(smth[0], memory);
  for (int i = 1; i < n; i++)
  {
    newS[i] = new TNewStack<MultiStackType>(*(A.newS[i]));

    int temp = smth[0] + countingSize;

    newS[i]->TNewStack<MultiStackType>::SetMas(smth[i], &memory[temp]);
    countingSize += smth[i];
  }
}
//--------------------------------------------------------------------------
template<typename MultiStackType>
void TMStack<MultiStackType>::Set(int _n, MultiStackType p)
{
  if (IsFull(_n))
    Repack(_n);

  newS[_n]->Put(p);
}
//--------------------------------------------------------------------------
template<typename MultiStackType>
MultiStackType TMStack<MultiStackType>::Get(int _n)
{
  if (IsEmpty(_n))
    throw TException("Empty");

  return newS[_n]->Get();
}
//--------------------------------------------------------------------------
template<typename MultiStackType>
bool TMStack<MultiStackType>::IsFull(int _n)
{
  return (newS[_n]->GetFreeMemory() <= 0);
}
//--------------------------------------------------------------------------
template<typename MultiStackType>
bool TMStack<MultiStackType>::IsEmpty(int _n)
{
  return (newS[_n]->GetFreeMemory() == newS[_n]->GetSize());
}
//--------------------------------------------------------------------------
template <typename MultiStackType>
int TMStack<MultiStackType>::GetFreeMemory()
{
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    count += newS[i]->GetFreeMemory();
  }

  return count;
}
//--------------------------------------------------------------------------
template <typename MultiStackType>
void TMStack<MultiStackType>::Repack(int k)
{
  cout << "Repacking starts" << endl;

  int FreeForNow = GetFreeMemory();
  int eq_add = FreeForNow / n;
  int full_add = FreeForNow % n;

  int* sizeNewOne = new int[n];
  MultiStackType** startNewOne = new MultiStackType*[n];
  MultiStackType** startOldOne = new MultiStackType*[n];

  for (int i = 0; i < n; i++)
    sizeNewOne[i] = eq_add + newS[i]->GetTop();

  sizeNewOne[k] += full_add;
  startNewOne[0] = startOldOne[0] = memory;

  for (int i = 1; i < n; i++)
  {
    startNewOne[i] = startNewOne[i - 1] + sizeNewOne[i - 1];
    startOldOne[i] = startOldOne[i - 1] + newS[i - 1]->GetSize();
  }

  for (int i = 0; i < n; i++)
  {
    if (startNewOne[i] <= startOldOne[i])
      for (int j = 0; j < newS[i]->GetTop(); j++)
        startNewOne[i][j] = startOldOne[i][j];

    else
    {
      int s = i + 1;

      for (s; s < n; s++)
        if (startNewOne[s] <= startOldOne[s])
          break;

      for (int j = s - 1; j >= i; j--)
        for (int r = newS[j]->GetTop() - 1; r >= 0; r--)
          startNewOne[j][r] = startOldOne[j][r];

      i = s - 1;
    }
  }

  for (int i = 0; i < n; i++)
    newS[i]->SetMas(sizeNewOne[i], startNewOne[i]);

  delete[] sizeNewOne;
  delete[] startNewOne;
  delete[] startOldOne;
}