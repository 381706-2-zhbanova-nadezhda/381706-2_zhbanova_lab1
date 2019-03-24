#ifndef __T_TREE
#define __T_TREE

#include <iostream>
#include <string>
#include <sstream>
#include "tstacklist.h"
#include "TTreeIter.h"

using namespace std;

class TTree
{
protected:
  TTree* pDown;
  TTree* pNext; // ������
  char d; // �����, ������ �� ������ ������
  int level; // �������, 0 -�����, 1 -������, 2 - �����, 3 - �����
  // ��� char d ������� ������ -1
  // ����������� ������ - ������, ��������� ����� ������
  // ������ ���������� ����������, ������������ � ������ TTree
  static int sizeMas;
  static char* mas;
  static TTree* start;	// ��������� �� ������ ����� ������
  static TTree* end;	// ��������� �� ����� ����� ������
  static TTree* _free;	// ��������� �� ������� ��������� ������
public:
  TTree( const char _d = 0 );
  TTree( const unsigned _l );
  TTree( const string& str );
  TTree( const TTree& a );
  ~TTree();

  TTree& operator=( const TTree& a );
  TTree& operator+=( const TTree& a );
  TTree& operator+=( char c );
  TTree& operator+=( const string& c );
  void* operator new ( unsigned int size_t );
  void operator delete ( void* d );

  void SetpDown( TTree* p );
  void SetpNext( TTree* p );
  void SetD( char _d );
  void SetLevel( int _level );

  TTree* GetpDown();
  TTree* GetpNext();
  char GetD();
  int GetLevel();

  string ToStr();
//  TTree* Clone();
  void Init( int size = 1000 ); // ������������� ����� ������ ������� 1000
  void GarbageCollector(); // ������ ������

  friend ostream& operator<<( ostream& o, const TTree& a )
  {
    o<<a.ToStr();
    return o;
  }
};

int GetLevelByString( string str );

#endif /*__T_STACK_LIST*/