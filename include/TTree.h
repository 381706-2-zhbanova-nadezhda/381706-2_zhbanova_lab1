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
  TTree* pDown; // pointer to the first element of next level
  TTree* pNext; // pointer to the next element of the same level
  char d; // array of marks for memory
  int level;
  // static variables
  static int sizeMas; // total memory size
  static char* mas; // 
  static TTree* start; // 
  static TTree* end; // 
  static TTree* _free; // pointer to the beginning of the free memory
public:
  // TTree( const char _d = 0 ); // create tree using letter
  TTree( const unsigned _l ); // create tree using level
  TTree( const string& str ); // create tree using any strings
  TTree( const TTree& a ); // copy constructor
  ~TTree(); // destructor

  TTree& operator=( const TTree& a ); // assignment
  TTree& operator+=( const TTree& a ); //
  TTree& operator+=( char c ); //
  TTree& operator+=( const string& c ); //
  void* operator new ( unsigned int size_t ); //
  void operator delete ( void* d ); //

  void SetpDown( TTree* p ); // set the first element of next level
  void SetpNext( TTree* p ); // set the next element of the same level
  void SetD( char _d ); //
  void SetLevel( int _level ); //set the level passed to the argument

  TTree* GetpDown(); //return the first element of next level
  TTree* GetpNext(); //return the next element of the same level
  char GetD(); //
  int GetLevel(); //return the current level

  string ToStr(); //
//  TTree* Clone(); //copying an object without data type binding
  void Init( int size = 1000 ); //
  void GarbageCollector(); //clean and redistribute a free memory

  friend ostream& operator<<( ostream& o, const TTree& a ) //overloading the stream output operator
  {
    o << a.ToStr();
    return o;
  }
};

int GetLevelByString( string str ); //

#endif /*__T_STACK_LIST*/