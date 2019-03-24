#include "TTreeIter.h"

TTreeIter::TTreeIter( TTree* r, int _level ) : level( _level )
{
  root = r;
  cur = root;

  while ( cur->GetpDown() != NULL && cur->GetLevel() < level )
  {
    st.Put( cur );
    cur = cur->GetpDown();
  }
}

void TTreeIter::Reset()
{
  st.Clear();
  cur = root;

  while ( cur->GetpDown() != NULL && cur->GetLevel() < level )
  {
    st.Put( cur );
    cur = cur->GetpDown();
  }
}

bool TTreeIter::IsEnd()
{
  return st.IsEmpty();
}

TTreeIter& TTreeIter::operator++()
{
  if ( cur->GetpNext() != NULL )
  {
    cur = cur->GetpNext();
    while ( cur -> GetpDown() != NULL && cur->GetLevel() < level )
    {
      st.Put( cur );
      cur = cur->GetpDown();
    }
  }
  else if ( !st.IsEmpty() )
  {
    cur = st.Get();
  }
  return *this;
}

TTree& TTreeIter::operator ()()
{
  return *cur;
}