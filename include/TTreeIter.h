#ifndef __T_TREE_ITER
#define __T_TREE_ITER

#include <iostream>
#include <string>

#include "TTree.h"

using namespace std;

class TTreeIter // Iterator
{
protected:
  int level;
  TTree* root;
  TTree* cur;
  TStackList <TTree*> st;
public:
  TTreeIter( TTree* r, int level = 3 );
  void Reset();
  bool IsEnd();
  TTree& operator ()();
  TTreeIter & operator ++();
};

#endif /*__T_TREE_ITER*/