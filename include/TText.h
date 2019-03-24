#ifndef __T_TEXT
#define __T_TEXT

#include <iostream>
#include <string>

#include "TTreeIter.h"
using namespace std;

class TText // level = 0, the highest
{
protected:
  TTree* root;
public:
  TText( const string& str );
  TText( TText &t );

  void Insert( int n, const string& str );	// insert string after n
  void Insert( TTree* start, TTree* str );	// insert s in start

  int Find( const string& str );
  //TTree* Find(TTree* string);

  char* Copy( int start, int len ); // �e����� ������ ������� � ������-�� �����
  TTree* Copy( TTree* start, int len );

  void Del( int start, int len );
  void Del( TTree* start, int len );
};

#endif /*__T_TEXT*/