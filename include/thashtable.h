#pragma once
#include "telement.h"

using namespace std;

template <typename HashTableType>
class THashTable
{
protected:
  static TElement<HashTableType> st;
  TElement<HashTableType>* node;
  int count;
  int size;
  int m;
  void Expansion(int _size);
  int Function(TString& A);
public:
  THashTable(const int _size = 1);
  THashTable(const THashTable<HashTableType>& A);
  ~THashTable();

  int GetCount() const { return count; }
  int GetSize() const { return size; }
  TElement<HashTableType>* GetNode() { return node; }

  void Add(TString& A, const HashTableType& H);
  void Add(TElement<HashTableType>& A);
  bool Delete(TString& A);
  HashTableType& Search(TString& A);
  bool IsSimple(const int num);
  template <typename Type>
  friend ostream& operator<<(ostream& ostr, const THashTable<Type>& A)
  {
  for (int i = 0; i < A.size; i++)
    if (A.node[i] != st)
      ostr << A.node[i] << endl;
  return ostr;
  }
};
//----------------------------------------------------------------------
template <typename HashTableType>
TElement<HashTableType> THashTable<HashTableType>::st;
//----------------------------------------------------------------------
template <typename HashTableType>
int THashTable<HashTableType>::Function(TString& A)
{
  unsigned int n = 0;
  for (int i = 0; i < A.GetCount(); i++)
    n = (n >> 1) + A[i];
  return n;
}
//----------------------------------------------------------------------
template <typename HashTableType>
void THashTable<HashTableType>::Expansion(int _size)
{
  if(_size <= size)
    throw 1;
  else if(_size > size)
  {
    while (IsSimple(_size) == 0)
      _size++;
    TElement<HashTableType>* tmp = new TElement<HashTableType>[_size];
    for (int i = 0; i < size; i++)
      tmp[i] = node[i];
    for (int i = size; i < _size; i++)
      tmp[i] = st;
    size = _size;
    delete[] node;
    node = tmp;
  }
}
//----------------------------------------------------------------------
template <typename HashTableType>
THashTable<HashTableType>::THashTable(const int _size)
{
  if (_size <= 0)
    throw 1;
  count = 0;
  size = _size;
  m = 2;
  if (size == 1)
    m = 1;
  node = new TElement<HashTableType>[size];
  for (int i = 0; i < size; i++)
    node[i] = st;
}
//----------------------------------------------------------------------
template <typename HashTableType>
THashTable<HashTableType>::THashTable(const THashTable<HashTableType>& A)
{
  count = A.count;
  size = A.size;
  m = A.m;
  node = new TElement<HashTableType>[size];
  for (int i = 0; i < size; i++)
    node[i] = A.node[i];
}
//----------------------------------------------------------------------
template <typename HashTableType>
THashTable<HashTableType>::~THashTable()
{
  count = 0;
  size = 0;
  delete[] node;
}
//----------------------------------------------------------------------
template <typename HashTableType>
void THashTable<HashTableType>::Add(TString& A, const HashTableType& H)
{
  if (count == size)
    Expansion(count*2);
  int i = Function(A);
  if (i > size)
    Expansion(i + 10);
  while (node[i] != st)
    i = (i + m) % size;
  node[i].SetKey(A);
  node[i].SetData(H);
  count++;
}
//----------------------------------------------------------------------
template <typename HashTableType>
void THashTable<HashTableType>::Add(TElement<HashTableType>& A)
{
  if (count == size)
    Expansion(count*2);
  int i = Function(A.GetKey());
  if (i > size)
    Expansion(i + 10);
  while (node[i] != st)
    i = (i + m) % size;
  node[i] = A;
  count++;
}
//----------------------------------------------------------------------
template <typename HashTableType>
bool THashTable<HashTableType>::Delete(TString& A)
{
  for(int j = 0; j < size; j++)
  {
    if(node[j].GetKey() == A)
    {
      node[j] = st;
      break;
    }
  }
  count--;
  //int i = Function(A);
  //while (node[i].GetKey() != A)
  //{
  //  if (node[i] == st)
  //    return false;
  //  i = (i + m) % size;
  //}
  //node[i] = st;
  return true;
}
//----------------------------------------------------------------------
template <typename HashTableType>
HashTableType& THashTable<HashTableType>::Search(TString& A)
{
  int i;
  for(i = 0; i < size; i++)
  {
    if(node[i].GetKey() == A)
      break;
  }
  //int i = Function(A);
  //while (node[i].GetKey() != A)
  //{
  //  i = (i + m) % size;
  //  if (node[i] == st)
  //    break;
  //}
  return node[i].GetData();
}
//----------------------------------------------------------------------
template <typename HashTableType>
bool THashTable<HashTableType>::IsSimple(const int num)
{
  for (int i = 2; i < num / 2; i++)
    if (num%i == 0) return false;
  return true;
}