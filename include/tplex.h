#pragma once

#include <iostream>
#include <stack>
#include "tpoint.h"
#include "tline.h"
#include "tcircle.h"

class TPlex: public TPoint
{
protected:
  TPoint *left;
  TPoint *right;
  virtual TPoint* Show(TPlex* p); //not used
public:
  TPlex();
  TPlex(TPoint* a, TPoint* b);
  TPlex(const TPlex& A);
  ~TPlex();
  TPoint GetR();
  TPoint GetL();
  void Del();
  TPlex& operator +=(TLine& A);
  // TPlex& Add(TPoint* a, TPoint* b); //instead of +=
  virtual void Show();
};
//----------------------------------------------------------------------
TPlex::TPlex()
{
  right = NULL;
  left = NULL;
}
//----------------------------------------------------------------------
TPlex::TPlex(TPoint* A, TPoint* B)
{
  TPlex* memory = dynamic_cast<TPlex*>(A);
  TPlex* memory2 = dynamic_cast<TPlex*>(B);
  if (memory != NULL)
    left = new TPlex(*memory);
  else
    left = new TPoint(*A);
  if (memory2 != NULL)
    right = new TPlex(*memory2);
  else
    right = new TPoint(*B);
}
//----------------------------------------------------------------------
TPlex::TPlex(const TPlex& plex)
{
  TPlex* memory = dynamic_cast<TPlex*>(plex.left);
  TPlex* memory2 = dynamic_cast<TPlex*>(plex.right);
  if (memory != NULL)
    left = new TPlex(*memory);
  else
    left = new TPoint(*plex.left);
  if (memory2 != NULL)
    right = new TPlex(*memory2);
  else
    right = new TPoint(*plex.right);
}
//----------------------------------------------------------------------
TPlex::~TPlex()
{
  Del();
}
//----------------------------------------------------------------------
TPoint TPlex::GetR()
{
  return *right;
}
//----------------------------------------------------------------------
TPoint TPlex::GetL()
{
  return *left;
}
//----------------------------------------------------------------------
void TPlex::Del()
{
  TPlex* tmp1 = dynamic_cast<TPlex*>(left);
  TPlex* tmp2 = dynamic_cast<TPlex*>(right);
  if (tmp1 != NULL)
    tmp1->Del(); //recursion
  else
    delete left;
  if (tmp2 != NULL)
    tmp2->Del(); //recursion
  else
    delete right;
}
//----------------------------------------------------------------------
TPlex& TPlex::operator +=(TLine& A)
{
  if (right == NULL && left == NULL)
  {
    left = A.GetPointA();
    right = A.GetPointB();
  }
  else
  {
    std::stack<TPoint*> memory;
    std::stack<TPoint*> memory2;
    memory.push(left);
    memory.push(right);
    memory2.push(this);
    memory2.push(this);
    bool flag = true;
    while (flag == true)
    {
      TPoint* tmp = memory.top();
      TPlex* pl = dynamic_cast<TPlex*>(memory2.top());
      if (*tmp != *A.GetPointA() && *tmp != *A.GetPointB())
      {
        TPlex* px = dynamic_cast<TPlex*>(tmp);
        if (px != NULL)
        {
          memory.push(px->left);
          memory.push(px->right);
          memory2.push(px);
          memory2.push(px);
        }
      }
      else if (*tmp == *A.GetPointA())
      {
        flag = false;
        if (*tmp == *pl->left)
        {
          pl->left = new TPlex(A.GetPointB(), A.GetPointA());
        }
        else
        {
          pl->right = new TPlex(A.GetPointB(), A.GetPointA());
        }
      }
      else if (*tmp == *A.GetPointB())
      {
        flag = false;
        if (*tmp == *pl->left)
          pl->left = new TPlex(A.GetPointA(), A.GetPointB());
        else
          pl->right = new TPlex(A.GetPointA(), A.GetPointB());
      }
    }
  }
  return *this;
}
//----------------------------------------------------------------------
//TPlex& TPlex::Add(TPoint* a, TPoint* b)
//{
//  if(left == 0 && right == 0)
//  {
//    left = a;
//    right = b;
//  }
//  else
//  {
//    std::stack<TPoint*> ar;
//    std::stack<TPoint*> pa;
//    ar.push(left);
//    ar.push(right);
//    bool f1 = true;
//    while(f1)
//    {
//      TPoint* p = ar.top();
//      TPlex* d = dynamic_cast<TPlex*>(pa.top());
//      pa.pop();
//      ar.pop();
//      if(p != a && p != b)
//      {
//        TPlex* p1 = dynamic_cast<TPlex*>(p);
//        if(p1 != 0)
//        {
//          ar.push(p1 -> left);
//          ar.push(p1 -> right);
//          pa.push(p1);
//          pa.push(p1);
//        }
//      }
//      else if( p == a)
//      {
//        f1 = false;
//        if(p == d -> left)
//        {
//          d -> left = new TPlex(b, a);
//        }
//        else
//        {
//          d -> right = new TPlex(b, a);
//        }
//      }
//      else if( p == b)
//      {
//        f1 = false;
//        if(p == d -> left)
//        {
//          d -> left = new TPlex(a, b);
//        }
//        else
//        {
//          d -> right = new TPlex(a, b);
//        }
//      }
//    }
//  }
//}
//----------------------------------------------------------------------
TPoint* TPlex::Show(TPlex* p)
{
  TPlex* lp = dynamic_cast<TPlex*>(p -> left);
  TPlex* rp = dynamic_cast<TPlex*>(p -> right);
  TPoint* tmp_l;
  TPoint* tmp_r;
  if(lp == NULL)
  {
    tmp_l = p -> left;
  }
  else
    tmp_r = Show(lp); //recursion
  if(rp == NULL)
  {
    tmp_r = p -> right;
  }
  else
    tmp_r = Show(rp); //recursion
  std::cout << "Line: " << *tmp_l << * tmp_r <<std::endl;
  return tmp_r;
}
//----------------------------------------------------------------------
void TPlex::Show()
{
  TPlex* memory = dynamic_cast<TPlex*>(left);
  TPlex* memory2 = dynamic_cast<TPlex*>(right);
  if (memory != NULL)
    memory->Show();
  else
    left->Show();
  if (memory2 != NULL)
    memory2->Show();
  else
    right->Show();
}