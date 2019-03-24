#include "TTree.h"

using namespace std;

int TTree::sizeMas = 0;
char* TTree::mas = NULL;
TTree* TTree::start = NULL;
TTree* TTree::end = NULL;
TTree* TTree::_free = NULL;

int GetLevelByString( string str )
{
  int level;
  if ( str.size() == 1 )
  {
    level = 4; // letter
    return level;
  }
  else
  {
    level = 3; // word
  }
  for( string::iterator it = str.begin(); it != str.end(); ++it )
  {
    if ( isspace(*it) )
      level = 2; // string
    if ( *it=='\n' )
    {
      level = 1; // multistring
      if ( *next(it)=='\n' )
      {
        level = 0; // text
        break;
      }
    }
  }
  return level;
}

bool ParagraphDelimeter(string str, int i) { return (str[i] == '\n' && str[i + 1] == '\n') ? true : false; }
bool StringDelimeter(string str, int i) { return (str[i] == '\n') ? true : false; }
bool WordDelimeter(string str, int i) { return isspace(str[i]); }
bool CharDelimeter(string str, int i) { return true; };

TTree::TTree( const char _d )
{
  Init();
  d = _d;
  pDown = NULL;
  pNext = NULL;
  level = 3;
}
TTree::TTree( const unsigned _l )
{
  if ( _l < 0 || _l > 3 )
    throw std::exception();
  Init();
  d = 0;
  pDown = NULL;
  pNext = NULL;
  level = _l;
}
TTree::TTree( const string& str )
{
  Init();
  d = 0;
  pNext = NULL;
  pDown = NULL;

  TTree* tmp;
  bool flag = true;

  int pos = 0;
  bool (*delim)( string, int );
  switch( GetLevelByString(str) )
  {
  case 0: // text
  {
    level = 0;
    delim = ParagraphDelimeter;
    break;
  }
  case 1: // multistring
  {
    level = 1;
    delim = StringDelimeter;
    break;
  }
  case 2: // string
  {
    level = 1;
    delim = WordDelimeter;
    break;
  }
  case 3: // word
  {
    level = 2;
    delim = CharDelimeter;
    break;
  }
  case 4: // letter
  {
    Init();
    d = str[0];
    pDown = NULL;
    pNext = NULL;
    level = 3;
    break;
  }
  default:
    throw std::exception();
  }

  for ( unsigned i = 0; i < str.size() - 1; i++ )
  {
    if (delim)
    {
      if (flag)
      {
        tmp = new TTree( std::string(str,pos, i) );
        pDown = tmp;
        flag = false;
      }
      else
      {
        tmp ->pNext = new TTree( std::string(str,pos, i - pos) );
        tmp = tmp -> pNext;
      }
      pos = i + 1;
    }
  }
}

TTree::TTree( const TTree& a )
{
  level = a.level;
  d = a.d;
  if ( a.pDown != NULL )
  pDown = new TTree( *(a.pDown) );
  else
  pDown = a.pDown;

  if ( a.pNext != NULL )
    pNext = new TTree( *(a.pNext) );
  else
  pNext = a.pNext;
}
TTree& TTree::operator=( const TTree& a )
{
  for ( TTreeIter t(this); !t.IsEnd(); t++ )
  {
    if ( t() != this )
      delete t();
  }

  level = a.level;
  d = a.d;
  if ( a.pDown != NULL )
    pDown = new TTree( *(a.pDown) );
  else
    pDown = a.pDown;

  if ( a.pNext != NULL )
    pNext = new TTree( *(a.pNext) );
  else
    pNext = a.pNext;

  return *this;
}

TTree::~TTree()
{
  for ( TTreeIter t(this); !t.IsEnd(); t++ )
  {
    delete t();
  }
}

TTree& TTree::operator+=( const TTree& a )
{
  TTree* tmp = this;
  // ���� ������� ������������� ������ ���������
  // (� ������ ����� �����, � ����� ������ - ������)
  if ( this->level < a.level )
    throw std::exception();
  while ( tmp->level != a.level ) // ����� �� ������, �� ������� ���� ���� �����
    tmp = tmp->pDown;
  while ( tmp->pNext != NULL ) // ����� �� ���������� �������� ������
    tmp = tmp->pNext;
  tmp->pNext = new TTree(a);
  return *this;
}
TTree& TTree::operator+=( char c )
{
  TTree symb(c);
  return ( *this += symb );
}
TTree& TTree::operator+=( const string& c )
{
  TTree symb(c);
  return ( *this += symb );
}

void* TTree::operator new ( unsigned int size_t )
{
  if( _free != NULL )
  {
    TTree* tmp = _free;
    if ( tmp->GetD() != -1)
    {
      throw std::exception( "Invalid deletion was performed" );
    }
    _free = _free -> pDown;
    return tmp;
    //TTree* a = _free;
    ////�� �� ������ ��������� ������
    //  //� �� ������ ��������� ���������
    //_free = _free->pDown;
    ////�������� ������� ���-�� ��������� ������
    //TTree* b = a;
    //for( int i = 0; i < sizeMas /*?size*/ && _free != 0; i++ )
    //{
    //  if ( b == 0 )
    //    throw std::exception( "��� ��������� ������" );
    //  else
    //    _free = _free->pDown;
    //}
  //return a;
  }
  else
  {
    throw std::exception( "Memory manager can't allocate more memory" );
  }
}
void TTree::operator delete ( void* a )
{
  //������� ������������� �� ��
  TTree* t = (TTree*)a;
  //���������� ������ � �������� ������
  t -> pDown = _free;
  _free = t;
  t -> d = -1;
}

void TTree::SetpDown( TTree* p )
{
  pDown = p;
}
void TTree::SetpNext( TTree* p )
{
  pNext = p;
}
void TTree::SetD( char _d )
{
  if( level == 3 )
    d =_d;
  else
    throw std::exception();
}
void TTree::SetLevel( int _level )
{
  level = _level;
}

TTree* TTree::GetpDown()
{
  return pDown;
}
TTree* TTree::GetpNext()
{
  return pNext;
}
char TTree::GetD()
{
  if( level == 3 )
    return d;
  else
    throw std::exception();
}
int TTree::GetLevel()
{
  return level;
}

std::string TTree::ToStr()
{
  stringstream stream;
  for ( TTreeIter t(this); !t.IsEnd(); t++ )
  {
    switch ( t().GetLevel() )
    {
      case 0:
        {
          stream<<"\n";
          break;
        }
      case 1:
        {
          stream<<"\n";
          break;
        }
      case 2:
        {
          stream<<" ";
          break;
        }
      case 3:
        {
          stream<<t().GetD();
          break;
        }
      default:
        throw std::exception();
    }
  }
  return stream.str();
//  TStackList <TTree*> t;
//  t.Put(this);
//  int l = 0;	// length of word
//  while ( !t.IsEmpty() )
//  {
//  	TTree* i = t.Get(); // get
//  	if ( i->level == 3 )
//  		l++;
//  	if ( i->pNext != 0 )
//  		t.Put( i->pNext );
//  	if( i->pDown != 0 )
//  		t.Put( i->pDown );
//  }
//
//  char *res = new char[l + 1];
//  int j = 0;
//
//  while ( !t.IsEmpty() )
//  {
//  	TTree* i = t.Get(); // get
//  	if ( i->level == 3 ) // if it is a word
//  		l++;
//  	if ( i->pNext != 0 )
//  		t.Put( i->pNext );
//  	if ( i->pDown != 0 )
//  		t.Put( i->pDown );
//  }
//  res[l] = 0;
//  return res;
}
//TTree* TTree::Clone()
//{
//  TTree* resTree = new TTree(*this);
//  TStackList <TTree*> st;
//  TStackList <TTree*> copy;
//  st.Put(this);
//  copy.Put( resTree );
//  while ( !st.IsEmpty() )
//  {
//  	TTree* tmp1 = st.Get();
//  	TTree* tmp2 = copy.Get();
//  	if ( tmp1->pDown != NULL )
//	{
//  	  tmp2->pDown = new TTree(*tmp1->pDown);
//	  st.Put(tmp1->pDown);
//      copy.Put(tmp2->pDown);
//    }
//    if (tmp1->pNext != NULL)
//    {
//      tmp2->pNext = new TTree(*(tmp1->pNext));
//      st.Put(tmp1->pNext);
//      copy.Put(tmp2->pNext);
//    }
//  }
//  return resTree;
//}
void TTree::Init( int size )
{
  if( mas == NULL )
  {
    sizeMas = size;
    mas = new char[sizeof(TTree)*size];
    start =(TTree*)(mas);
    _free = start;
    end = start;
    for( int i = 0; i < size-1; i++ )
    {
      end->pDown = (TTree*)&(mas[(i+1)*sizeof(TTree)]);
      end = end->pDown;
    }
  }
}
void TTree::GarbageCollector()
{
  //�������� ��� ������������� �� �� ��������, d = -1 - ������� �� �����
  _free = 0;
  for( int i = 0; i < sizeMas; i++ )
  {
    if(((TTree*)&(mas[i*sizeof(TTree)]))->d == -1 )
    {
      ((TTree*)&(mas[i*sizeof(TTree)]))->pDown = _free;
      _free = (TTree*)mas;
    }
  }
}