#ifndef __T_TEXT
#define __T_TEXT

#include <iostream>
#include <string>

#include "TTreeIter.h"
using namespace std;

class TText // level = 0, the highest
{
protected:
  TTree* root; //
public:
  TText( const string& str ); //
  TText( const TText &t ); //

  void Insert( int n, const string& str );  // insert string after n
  void Insert( TTree* start, TTree* str );  // insert s in start

  int Find( const string& str ); //
  int Find(TTree* string); //

  string Copy( int start, int len ); //
  TTree* Copy( TTree* start ); //

  void Del( int start, int len ); //
  void Del( TTree* start, int len ); //

  string ToStr();
};

#endif /*__T_TEXT*/