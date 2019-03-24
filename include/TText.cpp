#include "TText.h"

TText::TText( const string& str )
{
  root = new TTree( str );
}
TText::TText( TText &t )
{
  root = new TTree( *t.root );
}

void TText::Insert( int n, const string& str )
{
  int level = GetLevelByString( str );

}
void TText::Insert( TTree* start, TTree* string )
{
  TTree* tmp1 = string;
  TTree* tmp2 = root;
  while ( tmp2->GetLevel() != start->GetLevel() )
    tmp2 = tmp2->GetpDown();
  while ( tmp2 != start )
    tmp2 = tmp2->GetpNext();
  tmp1->SetpNext( tmp2->GetpNext() );
  tmp2->SetpNext( tmp1 );
}

int TText::Find( const string& str )
{
  int pos = 0;
  return pos;
}

//TTree* TText::Find(TTree* string) //?TTree* TText::Find( char* string)
//{
//
//}

char* TText::Copy( int start, int len )
{
  char* res = new char[len];
  return res;
}
TTree* TText::Copy( TTree* start, int len )
{
  TTree* res = new TTree(0);
  return res;
}

void TText::Del( int start, int len )
{
}
void TText::Del( TTree* start, int len )
{
}