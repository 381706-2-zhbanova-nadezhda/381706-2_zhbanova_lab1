#pragma once
#include "tablesee.h"

using namespace std;

#define INSERT_SORT 1
#define SELECTION_SORT 2
#define QUICK_SORT 3

template <typename SortTableType>
class TSortTable
{
protected:
  static TElement<SortTableType> stt;
  TElement<SortTableType>* node;
  int count;
  int size;
  void Expansion(const int _size);
public:
  TSortTable(const int _size = 1);
  TSortTable(const TTableSee<SortTableType>& A, const int num);
  TSortTable(const TSortTable<SortTableType>& A);
  ~TSortTable();

  int GetCount() const { return count; }
  int GetSize() const { return size; }

  bool Add(TElement<SortTableType>& A);
  TString& Add(const SortTableType& A);
  bool Delete(TElement<SortTableType>& A);
  bool Delete(const TString& A);

  TElement<SortTableType>& LineSearch(const TString& A) const;
  TElement<SortTableType>& BinarySearch(const TString& A) const;

  static void InsertSort(TTableSee<SortTableType>& A);
  static void SelectionSort(TTableSee<SortTableType>& A);
  static void QuickSort(TTableSee<SortTableType>& A, const int low, const int high);

  SortTableType& operator[](const TString& A) const;
  template <typename Type>  
  friend ostream& operator<<(ostream& ostr, const TSortTable<Type>& A);
};
//----------------------------------------------------------------------
template <typename SortTableType>
void TSortTable<SortTableType>::Expansion(const int _size)
{
  if ( _size > size )
  {
    TElement<SortTableType>* tmp = new TElement<SortTableType>[_size];
    for ( int i = 0; i < count; i++ )
      tmp[i] = node[i];
    for ( int i = count; i < _size; i++ )
      tmp[i] = stt;
    size = _size;
    delete[] node;
    node = tmp;
  }
  else
    throw TException( "Error" );
}
//----------------------------------------------------------------------
template <typename SortTableType>
TElement<SortTableType> TSortTable<SortTableType>::stt;
//----------------------------------------------------------------------
template <typename SortTableType>
TSortTable<SortTableType>::TSortTable(const int _size)
{
  if ( _size <= 0 )
    throw 2;
  size = _size;
  count = 0;
  node = new TElement<SortTableType>[size];
  for ( int i = 0; i < size; i++ )
    node[i] = stt;
}
//----------------------------------------------------------------------
template <typename SortTableType>
TSortTable<SortTableType>::TSortTable(const TSortTable<SortTableType>& A)
{
  size = A.size;
  count = A.count;
  node = new TElement<SortTableType>[size];
  for ( int i = 0; i < size; i++ )
    node[i] = A.node[i];
}
//----------------------------------------------------------------------
template <typename SortTableType>
TSortTable<SortTableType>::TSortTable(const TTableSee<SortTableType>& A, const int num)
{
  size = A.GetSize();
  count = A.GetCount();
  TTableSee<SortTableType> copy_t(A);
  if (num == INSERT_SORT)
    TSortTable<SortTableType>::InsertSort(copy_t);
  else if (num == SELECTION_SORT)
    TSortTable<SortTableType>::SelectionSort(copy_t);
  else if (num == QUICK_SORT)
    TSortTable<SortTableType>::QuickSort(copy_t, 0, copy_t.GetCount() - 1);
  node = new TElement<SortTableType>[size];
  for (int i = 0; i < count; i++)
    node[i] = copy_t.GetNode()[i];
}
//----------------------------------------------------------------------
template <typename SortTableType>
TSortTable<SortTableType>::~TSortTable()
{
  count = size = 0;
  delete[] node;
}
//----------------------------------------------------------------------
template <typename SortTableType>
bool TSortTable<SortTableType>::Add(TElement<SortTableType>& A)
{
  bool flag = false;
  if ( count == 0 )
  {
    node[count] = A;
    count++;
    return true;
  }
  if ( count == size )
    Expansion( count * 2 );
  TElement<SortTableType> tmp;
  for ( int i = 0; i <= count; i++ )
  {
    if ( node[i].GetKey() < A.GetKey() && i != count )
      continue;
    else if ( node[i].GetKey() > A.GetKey() && flag == false )
    {
      flag = true;
      tmp = node[i];
      node[i] = A;
      continue;
    }
    else if ( flag == true )
    {
      TElement<SortTableType> temp = node[i];
      node[i] = tmp;
      tmp = temp;
    }
    else if ( i == count && flag == false )
    {
      node[count] = A;
      flag = true;
    }
  }
  count++;
  return flag;
}
//----------------------------------------------------------------------
template <typename SortTableType>
TString& TSortTable<SortTableType>::Add(const SortTableType& A)
{
  if ( size == count )
    Expansion( count * 2 );
  node[count].SetData(A);
  TString string( "Key" );
  if ( count == 0 ) 
  {
    node[count].SetKey(string);
    count++;
    return node[count - 1].GetKey();
  }
  else
  {
    TString string1( &( node[count - 1].GetKey().GetMemory()[0] ) );
    string = string1;
    node[count].SetKey(string);
    TElement<SortTableType> temp = node[count - 1];
    node[count - 1] = node[count];
    node[count] = temp;
  }
  count++;
  return node[count - 2].GetKey();
}
//----------------------------------------------------------------------
template <typename SortTableType>
bool TSortTable<SortTableType>::Delete(TElement<SortTableType>& A)
{
  int left = 0;
  int right = count;
  int current = count / 2;
  bool flag = false;
  while ( right - left >= 1 )
    if ( node[current].GetKey() < A.GetKey() )
    {
      left = current;
      current = (right + left) / 2;
    }
    else if ( node[current].GetKey() > A.GetKey() )
    {
      right = current;
      current = (right - left) / 2;
    }
    else if ( node[current].GetKey() == A.GetKey() )
    {
      for ( int i = current; i < count - 1; i++ )
        node[i] = node[i + 1];
      count--;
      flag = true;
      break;
    }
  return flag;
}
//----------------------------------------------------------------------
template <typename SortTableType>
bool TSortTable<SortTableType>::Delete(const TString& A)
{
  int left = 0;
  int right = count;
  int current = count / 2;
  bool flag = false;
  while ( right - left >= 1 )
    if ( node[current].GetKey() < A )
    {
      left = current;
      current = (right + left) / 2;
    }
    else if (node[current].GetKey() > A )
    {
      right = current;
      current = (right - left) / 2;
    }
    else if ( node[current].GetKey() == A )
    {
      for ( int i = current; i < count - 1; i++ )
        node[i] = node[i + 1];
      count--;
      flag = true;
      break;
    }
  return flag;
}
//----------------------------------------------------------------------
template <typename SortTableType>
TElement<SortTableType>& TSortTable<SortTableType>::LineSearch(const TString& A) const
{
  for ( int current = 0; current < count; current++ )
  {
    if ( node[current].GetKey() == A )
      return node[current];
  }
  return stt;
}
//----------------------------------------------------------------------
template <typename SortTableType>
TElement<SortTableType>& TSortTable<SortTableType>::BinarySearch(const TString& A) const
{
  int left = 0;
  int right = count;
  int cur = count / 2;
  int tmp = count / 2;
  while (right - left >= 1)
  {
    if (node[cur].GetKey() < A)
    {
      left = cur;
      cur = (right + left) / 2;
    }
    else if (node[cur].GetKey() > A)
    {
      right = cur;
      cur = (right - left) / 2;
    }
    else if (node[cur].GetKey() == A)
      return node[cur];
    if (right - left == 1)
      break;
  }
  return stt;
}
//----------------------------------------------------------------------
template <typename SortTableType>
void TSortTable<SortTableType>::InsertSort(TTableSee<SortTableType>& A)
{
  for ( int i = 1; i < A.GetCount(); i++ )
  {
    TElement<SortTableType> temp = A.GetNode()[i];
    int j = i;
    while ( j > 0 && A.GetNode()[j - 1].GetKey() > temp.GetKey() )
    {
      A.GetNode()[j] = A.GetNode()[j - 1];
      j--;
    }
    A.GetNode()[j] = temp;
  }
}
//----------------------------------------------------------------------
template <typename SortTableType>
void TSortTable<SortTableType>::QuickSort(TTableSee<SortTableType>& A, const int low, const int high)
{
  int i = low, j = high;
  TElement<SortTableType> d;
  TElement<SortTableType> m = A.GetNode()[(low + high) / 2];
  while (i <= j)
  {
    for (; A.GetNode()[i].GetKey() < m.GetKey(); i++);
    for (; A.GetNode()[j].GetKey() > m.GetKey(); j--);
    if (i <= j)
    {
      d = A.GetNode()[i];
      A.GetNode()[i++] = A.GetNode()[j];
      A.GetNode()[j--] = d;
    }
  }
  if (low < j)
    QuickSort(A, low, j);
  if (i < high)
    QuickSort(A, i, high);
}
//----------------------------------------------------------------------
template <typename SortTableType>
void TSortTable<SortTableType>::SelectionSort(TTableSee<SortTableType>& A)
{
  TElement<SortTableType> temp;
  int min;
  for ( int i = 0; i < A.GetCount() -1 ; i++ )
  {
    min = i;
    for ( int j = i + 1; j < A.GetCount(); j++ )
    {
      if (A.GetNode()[j].GetKey() < A.GetNode()[min].GetKey())
        min = j;
    }
    temp = A.GetNode()[i];
    A.GetNode()[i] = A.GetNode()[min];
    A.GetNode()[min] = temp;
  }
}
//----------------------------------------------------------------------
template <typename SortTableType>
SortTableType& TSortTable<SortTableType>::operator[](const TString& A) const
{
  return LineSearch(A).GetData();
}
//----------------------------------------------------------------------
template <typename Type>
ostream& operator<<(ostream& ostr, const TSortTable<Type>& A)
{
  for ( int i = 0; i < A.GetCount(); i++ )
    ostr << A.node[i] << endl;
  return ostr;
}