#include "TText.h"

TText::TText( const string& str )
{
  root = new TTree( str );
}
TText::TText( const TText &t )
{
  root = new TTree( *t.root );
}

void TText::Insert( int n, const string& str )
{
  int level = GetLevelByString( str );

  if (level > root->GetLevel()) throw std::exception();

  int count = 0;
  TTreeIter t(root);
  for ( ; !t.IsEnd(); t++ )
  {
    if (t().GetLevel() == level) {
      count++;
    }
    if (count == n) {
      TTree* tmp;
      if (level != 4){
        tmp = new TTree(level);
        tmp->SetpDown(new TTree(str));
      } else {
        tmp = new TTree(str);
      }
      tmp->SetpNext(t().GetpNext());
      t().SetpNext(tmp);
      break;
    }
  }
}

void TText::Insert( TTree* start, TTree* string )
{
  int level = start->GetLevel();
  if ( level > root->GetLevel() || level != string->GetLevel() ) throw std::exception();

  for ( TTreeIter t(root); !t.IsEnd(); t++ )
  {
    if ( &t() == start ) {
      TTree* tmp;
      if (level != 4){
        tmp = new TTree(level);
        tmp->SetpDown(new TTree(*string));
      } else {
        tmp = new TTree(*string);
      }
      tmp->SetpNext(t().GetpNext());
      t().SetpNext(tmp);
      break;
    }
  }
}

int TText::Find( const string& str )
{
  TTree tmp(str);
  return Find(tmp);
}

int TText::Find(TTree* string)
{
  TTreeIter t1(root);
  TTreeIter t2(string);

  bool flag = false;
  int pos = 0;

  for ( ; !t1.IsEnd(); t1++){
    pos++;
    if (t1().GetD() == t2().GetD()) {
      flag = true;
      for (TTreeIter t2_tmp(string); !t1.IsEnd(), !t2_tmp.IsEnd(); t1++, t2_tmp++){
       if (t1().GetD() != t2_tmp().GetD()) {
         flag = false;
         break;
       }
      }
    }
    if (flag == true) break;
  }
  
  return pos;
}

string TText::Copy( int start, int len )
{
  return root->ToStr().substr(start,len);
}
TTree* TText::Copy( TTree* start )
{
  TTree* res = NULL;
  for ( TTreeIter t(root); !t.IsEnd(); t++ )
  {
    if ( &t() == start ) {
      res = new TTree(*start);
    }
  }
  return res;
}

void TText::Del( int start, int len )
{
  string tmp = root->ToStr();
  tmp.erase(start,len);
  root = new TTree(tmp);
}
void TText::Del( TTree* start, int len )
{
  int pos = 0;
  for ( TTreeIter t(root); !t.IsEnd(); t++ )
  {
    pos++;
    if ( &t() == start ) {
      break;
    }
  }
  Del(pos,len);
}

string TText::ToStr(){
  return root->ToStr();
}
