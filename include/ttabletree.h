#pragma once
#include "telemtree.h"
#include "tstacklist.h"

using namespace std;

template <typename TableTreeType>
class TTableTree
{
protected:
  static TElemTree<TableTreeType> ttt;
  int count;
  TElemTree<TableTreeType>* node;
public:
  TTableTree();
  TTableTree(const TTableTree<TableTreeType>& A);
  ~TTableTree();

  int GetCount() const { return count; }
  TElemTree<TableTreeType>* GetNode() const { return node; }

  TElemTree<TableTreeType>* Add(TElemTree<TableTreeType>& A);
  bool Delete(const TString& A);
  TElemTree<TableTreeType>& Search(const TString& A) const;
  TableTreeType& operator[](const TString& A) const;

  template <typename Type>
  friend ostream& operator<<(ostream& ostr, const TTableTree<Type>& A);
};
//----------------------------------------------------------------------
template <typename TableTreeType>
TElemTree<TableTreeType> TTableTree<TableTreeType>::ttt;
//----------------------------------------------------------------------
template <typename TableTreeType>
TTableTree<TableTreeType>::TTableTree() : node(NULL), count(0)
{
}
//----------------------------------------------------------------------
template <typename TableTreeType>
TTableTree<TableTreeType>::TTableTree(const TTableTree<TableTreeType>& A)
{
  count = A.count;
  node = new TElemTree<TableTreeType>(*(A.node));
  TStackList<TElemTree<TableTreeType>*> st1;
  TStackList<TElemTree<TableTreeType>*> st2;
  st1.Put(node);
  st2.Put(A.node);
  while (st2.IsEmpty() != true)
  {
    TElemTree<TableTreeType>* temp1 = st1.Get();
    TElemTree<TableTreeType>* temp2 = st2.Get();
    if (temp2->GetLeft() != NULL)
    {
      temp1->SetLeft(new TElemTree<TableTreeType>(*(temp2->GetLeft())));
      st1.Put(temp1->GetLeft());
      st2.Put(temp2->GetLeft());
      temp1->GetLeft()->SetParent(temp1);
    }
    if (temp2->GetRight() != NULL)
    {
      temp1->SetRight(new TElemTree<TableTreeType>(*(temp2->GetRight())));
      st1.Put(temp1->GetRight());
      st2.Put(temp2->GetRight());
      temp1->GetRight()->SetParent(temp1);
    }
  }
}
//----------------------------------------------------------------------
template <typename TableTreeType>
TTableTree<TableTreeType>::~TTableTree()
{
  TStackList<TElemTree<TableTreeType>*> st1;
  st1.Put(node);
  while (st1.IsEmpty() != true)
  {
    TElemTree<TableTreeType>* temp = st1.Get();
    if (temp != NULL)
    {
      if (temp->GetLeft() != NULL)
        st1.Put(temp->GetLeft());
      if (temp->GetRight() != NULL)
        st1.Put(temp->GetRight());
      delete temp;
    }
  }
}
//----------------------------------------------------------------------
template <typename TableTreeType>
TElemTree<TableTreeType>* TTableTree<TableTreeType>::Add(TElemTree<TableTreeType>& A)
{
  if (count == 0)
  {
    node = new TElemTree<TableTreeType>(A);
    count++;
    return node;
  }
  else
  {
    TElemTree<TableTreeType>* a;
    TElemTree<TableTreeType>* b = node;
    while (b != NULL)
    {
      a = b;
      if (A.GetKey() > b->GetKey())
        b = b->GetRight();
      else if (A.GetKey() < b->GetKey())
        b = b->GetLeft();
      else
        throw TException("Error");
    }
    count++;
    if (A.GetKey() > a->GetKey())
    {
      a->SetRight(new TElemTree<TableTreeType>(A));
      a->GetRight()->SetParent(a);
      b = a->GetRight();
    }
    else
    {
      a->SetLeft(new TElemTree<TableTreeType>(A));
      a->GetLeft()->SetParent(a);
      b = a->GetLeft();
    }
    return b;
  }
}
//----------------------------------------------------------------------
template <typename TableTreeType>
bool TTableTree<TableTreeType>::Delete(const TString& A)
{
  bool flag = false;
  TElemTree<TableTreeType>* a;
  TElemTree<TableTreeType>* b = node;
  while (b != NULL)
  {
    if (A > b->GetKey())
    {
      a = b;
      b = b->GetRight();
    }
    else if (A < b->GetKey())
    {
      a = b;
      b = b->GetLeft();
    }
    else
    {
      flag = true;
      break;
    }
  }
  if (b == node && flag == true)
  {
    node = node->GetRight();
    TElemTree<TableTreeType>* i = b->GetRight();
    if (i != NULL)
    {
      while (i->GetLeft() != NULL)
        i = i->GetLeft();
      i->SetLeft(b->GetLeft());
      if (i->GetLeft() != NULL)
        i->GetLeft()->SetParent(i);
    }
  }
  else if (flag == true && A == a->GetLeft()->GetKey())
  {
    a->SetLeft(b->GetRight());
    TElemTree<TableTreeType>* i = b->GetRight();
    if (i != NULL)
    {
      while (i->GetLeft() != NULL)
        i = i->GetLeft();
      i->SetLeft(b->GetLeft());
      if (i->GetLeft() != NULL)
        i->GetLeft()->SetParent(i);
    }
  }
  else if (flag == true && A == a->GetRight()->GetKey())
  {
    a->SetRight(b->GetRight());
    TElemTree<TableTreeType>* i = b->GetRight();
    if (i != NULL)
    {
      while (i->GetLeft() != NULL)
        i = i->GetLeft();
      i->SetLeft(b->GetLeft());
      if (i->GetLeft() != NULL)
        i->GetLeft()->SetParent(i);
    }
  }
  if (flag == true)
  {
    delete b;
    count--;
  }
  return flag;
}
//----------------------------------------------------------------------
template <typename TableTreeType>
TElemTree<TableTreeType>& TTableTree<TableTreeType>::Search(const TString& A) const
{
  if (count == 0)
    return ttt;
  TElemTree<TableTreeType>* temp = node;
  while (temp != NULL)
  {
    if (temp->GetKey() < A)
      temp = temp->GetRight();
    else if (temp->GetKey() > A)
      temp = temp->GetLeft();
    else
      return *temp;
  }
  return ttt;
}
//----------------------------------------------------------------------
template <typename TableTreeType>
TableTreeType& TTableTree<TableTreeType>::operator[](const TString& A) const
{
  return Search(A).GetData();
}
//----------------------------------------------------------------------
template <typename Type>
ostream& operator<<(ostream& ostr, const TTableTree<Type>& A)
{
  TStackList<TElemTree<Type>*> st1;
  st1.Put(A.GetNode());
  while (st1.IsEmpty() != true)
  {
    TElemTree<Type>* temp = st1.Get();
    if (temp->GetRight() != NULL)
      st1.Put(temp->GetRight());
    if (temp->GetLeft() != NULL)
      st1.Put(temp->GetLeft());
    ostr << *temp << endl;
  }
  return ostr;
}