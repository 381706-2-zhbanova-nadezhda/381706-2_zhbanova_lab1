#pragma once
#include "telement.h"

using namespace std;

template <typename TableSeeType>
class TTableSee
{
protected:
  static TElement<TableSeeType> st;
  TElement<TableSeeType>* node;
  int size;
  int count;
  void Expansion(const int _size);
public:
  TTableSee(const int _size = 1);
  TTableSee(const TTableSee<TableSeeType>& A);
  ~TTableSee();

  int GetCount() const { return count; }
  int GetSize() const { return size; }
  TElement<TableSeeType>* GetNode() { return node; }

  bool Add(const TElement<TableSeeType>& A);
  bool Delete(TElement<TableSeeType>& A);
  TString& Add(const TableSeeType& A);
  bool Delete(const TString& A);

  TElement<TableSeeType>& Search(const TString& A) const;
  TableSeeType& operator[](const TString& A) const;
  template <typename Op>
  friend ostream& operator<<(ostream& ostr, const TTableSee<Op>& A);
};
//----------------------------------------------------------------------
template <typename TableSeeType>
void TTableSee<TableSeeType>::Expansion(const int _size)
{
  if (_size > size)
  {
    TElement<TableSeeType>* tmp = new TElement<TableSeeType>[_size];
    for (int i = 0; i < count; i++)
      tmp[i] = node[i];
    for (int i = count; i < _size; i++)
      tmp[i] = st;
    size = _size;
    delete[] node;
    node = tmp;
  }
  else
    throw TException("Error");
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TElement<TableSeeType> TTableSee<TableSeeType>::st;
//----------------------------------------------------------------------
template <typename TableSeeType>
TTableSee<TableSeeType>::TTableSee(const int _size)
{
  if (_size < 0)
    throw TException("Error");
  size = _size;
  count = 0;
  node = new TElement<TableSeeType>[size];
  for (int i = 0; i < size; i++)
    node[i] = st;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TTableSee<TableSeeType>::TTableSee(const TTableSee<TableSeeType>& A)
{
  size = A.size;
  count = A.count;
  node = new TElement<TableSeeType>[size];
  for (int i = 0; i < size; i++)
    node[i] = A.node[i];
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TTableSee<TableSeeType>::~TTableSee()
{
  count = size = 0;
  delete[] node;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
bool TTableSee<TableSeeType>::Add(const TElement<TableSeeType>& A)
{
  if (size == count)
    Expansion(count * 2);
  node[count] = A;
  count++;
  return true;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TString& TTableSee<TableSeeType>::Add(const TableSeeType& A)
{
  if (size == count)
    Expansion(count * 2);
  node[count].SetData(A);
  TString string("Key");
  node[count].SetKey(string);
  count++;
  return node[count - 1].GetKey();
}
//----------------------------------------------------------------------
template <typename TableSeeType>
bool TTableSee<TableSeeType>::Delete(TElement<TableSeeType>& A)
{
  if (count == 0)
    return false;
  bool flag = false;
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == A.GetKey())
    {
      for (int j = i; j < count - 1; j++)
        node[j] = node[j + 1];
      flag = true;
      break;
    }
  if (flag == true)
    count--;
  return flag;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
bool TTableSee<TableSeeType>::Delete(const TString& A)
{
  if (count == 0)
    return false;
  bool flag = false;
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == A)
    {
      for (int j = i; j < count - 1; j++)
        node[j] = node[j + 1];
      flag = true;
      break;
    }
  if (flag == true)
    count--;
  return flag;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TElement<TableSeeType>& TTableSee<TableSeeType>::Search(const TString& A) const
{
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == A)
      return node[i];
  return st;
}
//----------------------------------------------------------------------
template <typename TableSeeType>
TableSeeType& TTableSee<TableSeeType>::operator[](const TString& A) const
{
  return Search(A).GetData();
}
//----------------------------------------------------------------------
template <typename Op>
ostream& operator<<(ostream& ostr, const TTableSee<Op>& A)
{
  for (int i = 0; i < A.GetCount(); i++)
    ostr << A.node[i] << endl;
  return ostr;
}