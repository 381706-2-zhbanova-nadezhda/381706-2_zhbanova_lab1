#pragma once
#include <iostream>
#include <cstring>
#include "exception.h"

class TString
{
protected:
  char* memory;
  int count;
public:
  TString();
  TString(const char* A);
  TString(const TString& A);
  ~TString();

  int GetCount() const;
  char* GetMemory();

  TString& operator=(const TString& A);
  bool operator==(const TString& A) const;
  bool operator!=(const TString& A) const;
  bool operator<(const TString& A) const;
  bool operator>(const TString& A) const;
  char& operator[](const int a) const;
};
//----------------------------------------------------------------------
TString::TString()
{
  count = 0;
  memory = NULL;
}
//----------------------------------------------------------------------
TString::TString(const char* A)
{
  count = strlen(A);
  memory = new char[count + 1];
  for (int i = 0; i < count; i++)
    memory[i] = A[i];
  memory[count] = '\0';
}
//----------------------------------------------------------------------
TString::TString(const TString& A)
{
  count = A.count;
  memory = new char[count + 1];
  for (int i = 0; i < count; i++)
    memory[i] = A.memory[i];
   memory[count] = '\0';
}
//----------------------------------------------------------------------
TString::~TString()
{
  count = 0;
  delete[] memory;
}
//----------------------------------------------------------------------
int TString::GetCount() const
{
  return count;
}
//----------------------------------------------------------------------
char* TString::GetMemory()
{
  return memory;
}
//----------------------------------------------------------------------
TString& TString::operator=(const TString& A)
{
  count = A.count;
  delete[] memory;
  memory = new char[count + 1];
  for (int i = 0; i < count; i++)
    memory[i] = A.memory[i];
  memory[count] = '\0';
  return *this;
}
//----------------------------------------------------------------------
bool TString::operator==(const TString& A) const
{
  if (count != A.count)
    return false;
  for (int i = 0; i < count; i++)
    if (memory[i] != A.memory[i])
      return false;
  return true;
}
//----------------------------------------------------------------------
bool TString::operator!=(const TString& A) const
{
  if (count != A.count)
    return true;
  for (int i = 0; i < count; i++)
    if (memory[i] != A.memory[i])
      return true;
  return false;
}
//----------------------------------------------------------------------
bool TString::operator<(const TString& A) const
{
  bool result = false;
  if (count < A.count)
    return true;
  else if (count > A.count)
    return false;
  else
  {
    for (int i = 0; i < count; i++)
      if (memory[i] < A.memory[i])
      {
        result = true;
        break;
      }
  }
  return result;
}
//----------------------------------------------------------------------
bool TString::operator>(const TString& A) const
{
  bool result = false;
  if (count < A.count)
    return false;
  else if (count > A.count)
    return true;
  else
    for (int i = 0; i < count; i++)
      if (memory[i] > A.memory[i])
      {
        result = true;
        break;
      }
  return result;
}
//----------------------------------------------------------------------
char& TString::operator[](const int a) const
{
  if (a < 0 || a > count - 1)
    throw TException("Error");
  return memory[a];
}