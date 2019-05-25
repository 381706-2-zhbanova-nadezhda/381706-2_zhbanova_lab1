#pragma once

#include "tstring.h"
#include <iostream>

using namespace std;

template <typename ElemTreeType>
class TElemTree
{
protected:
  TString key;
  ElemTreeType data;
  TElemTree<ElemTreeType>* left;
  TElemTree<ElemTreeType>* right;
  TElemTree<ElemTreeType>* parent;
public:
  TElemTree();
  TElemTree(const ElemTreeType& _data, const TString& A, TElemTree<ElemTreeType>* _left = NULL,
      TElemTree<ElemTreeType>* _right = NULL, TElemTree<ElemTreeType>* _parent = NULL);
  TElemTree(const TElemTree<ElemTreeType>& A);
  ~TElemTree();
  TElemTree<ElemTreeType>& operator=(const TElemTree<ElemTreeType>& A);

  bool operator==(const TElemTree<ElemTreeType>& A) const;
  bool operator!=(const TElemTree<ElemTreeType>& A) const;

  ElemTreeType& GetData() { return data; }
  TString& GetKey() { return key; }
  TElemTree<ElemTreeType>* GetLeft() { return left; }
  TElemTree<ElemTreeType>* GetRight() { return right; }
  TElemTree<ElemTreeType>* GetParent() { return parent; }

  void SetData(const ElemTreeType& A);
  void SetKey(const TString& A);
  void SetLeft(TElemTree<ElemTreeType>* A);
  void SetRight(TElemTree<ElemTreeType>* A);
  void SetParent(TElemTree<ElemTreeType>* A);

  template <typename Type>
  friend ostream& operator<<(ostream& ostr, TElemTree<Type>& A);
};
//----------------------------------------------------------------------
template <typename ElemTreeType>
TElemTree<ElemTreeType>::TElemTree() : left(NULL), right(NULL), parent(NULL)
{
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
TElemTree<ElemTreeType>::TElemTree(const ElemTreeType& _data, const TString& A, TElemTree<ElemTreeType>* _left,
  TElemTree<ElemTreeType>* _right, TElemTree<ElemTreeType>* _parent) : data(_data), key(A), left(_left), right(_right), parent(_parent)
{
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
TElemTree<ElemTreeType>::TElemTree(const TElemTree<ElemTreeType>& A) : data(A.data), key(A.key), left(NULL), right(NULL), parent(NULL)
{
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
TElemTree<ElemTreeType>::~TElemTree()
{
  left = NULL;
  right = NULL;
  parent = NULL;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
TElemTree<ElemTreeType>& TElemTree<ElemTreeType>::operator=(const TElemTree<ElemTreeType>& A)
{
  if (this != &A)
  {
    left = A.left;
    right = A.right;
    parent = A.parent;
    key = A.key;
    data = A.data;
  }
  return *this;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
bool TElemTree<ElemTreeType>::operator==(const TElemTree<ElemTreeType>& A) const
{
  return (key == A.key && data == A.data) ? true : false ;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
bool TElemTree<ElemTreeType>::operator!=(const TElemTree<ElemTreeType>& A) const
{
  return !(*this == A);
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
void TElemTree<ElemTreeType>::SetData(const ElemTreeType& A)
{
  data = A;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
void TElemTree<ElemTreeType>::SetKey(const TString& A)
{
  key = A;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
void TElemTree<ElemTreeType>::SetLeft(TElemTree<ElemTreeType>* A)
{
  left = A;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
void TElemTree<ElemTreeType>::SetRight(TElemTree<ElemTreeType>* A)
{
  right = A;
}
//----------------------------------------------------------------------
template <typename ElemTreeType>
void TElemTree<ElemTreeType>::SetParent(TElemTree<ElemTreeType>* A)
{
  parent = A;
}
//----------------------------------------------------------------------
template <typename Type>
ostream& operator<<(ostream& ostr, TElemTree<Type>& A)
{
  ostr << A.GetKey().GetMemory() << "  " << "|  ";
  ostr << A.GetData() << endl;
  return ostr;
}