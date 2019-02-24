#pragma once

#include <iostream>
#include "exception.h"
#include "tmonomial.h"

using namespace std;

class TPolynomial
{
protected:
  TMonomial *start;
  int n;          //поле размерности монома 
  int k;       //количество элементов
public:
  TPolynomial();
  TPolynomial(int _n);
  TPolynomial(const TPolynomial &A);
  ~TPolynomial();

  int GetN();
  int GetSize();
  TMonomial* GetStart();
  TPolynomial operator-(TPolynomial &A);
  TPolynomial operator+(TPolynomial &A);
  TPolynomial& operator=(const TPolynomial &A);
  bool operator==(const TPolynomial &A);
  bool operator!=(const TPolynomial &p);
  TPolynomial operator*(TPolynomial &A);
  TPolynomial& operator+=(TMonomial &m);
  TPolynomial& operator-=(TMonomial &m);
  friend std::ostream& operator<<(std::ostream& _s, TPolynomial& Tm);
};

TPolynomial::TPolynomial()
{
  n = 0;
  k = 0;
  start = NULL;
}

TPolynomial::TPolynomial(int _n)
{
  if (_n <= 0)
    throw TException("Error");
  n = _n;
  k = 0;
  start = NULL;
}

TPolynomial::TPolynomial(const TPolynomial &p)
{
  n = p.n;
  k = p.k;
  if (p.start == NULL)
	start = NULL;
  else {
	start = new TMonomial(*p.start);
	for (TMonomial* it = p.start->GetNext(); it != NULL; it=it->GetNext()){
		start->SetNext(new TMonomial(*it));
	}
  }
}

TPolynomial::~TPolynomial()
{
  if (start == NULL)
	  return;
  TMonomial* next_el;
  for (TMonomial* it = start; it != NULL;){
	  next_el = it->GetNext();
	  it->~TMonomial();
	  it = next_el;
  }
}

int TPolynomial::GetN()
{
  return n;
}

int TPolynomial::GetSize()
{
  return k;
}

TMonomial* TPolynomial::GetStart()
{
  return start;
}

TPolynomial& TPolynomial::operator=(const TPolynomial &p)
{
	if (*this != p) {
		if (start != NULL){
			TMonomial* next_el;
			for (TMonomial* it = start; it != NULL;){
				next_el = it->GetNext();
				it->~TMonomial();
				it = next_el;
			}
		}
		
		start = new TMonomial(*p.start);
		TMonomial* src_el = start;
		for (TMonomial* it = p.start->GetNext(); it != NULL;it=it -> GetNext()){
			src_el -> SetNext(new TMonomial(*it));
			src_el = src_el -> GetNext();
		}

		n = p.n;
		k = p.k;
	}
	return *this;
}
  
TPolynomial &TPolynomial::operator+=(TMonomial &m)
{
  if (n != m.GetN())
    throw TException("Error");
  if (m.GetCoeff() == 0)
    return *this;
  if (start == NULL) {
    start = new TMonomial(m);
	k ++;
  }
  else
  {
	  TMonomial* last_el = NULL;
	  for ( TMonomial *ptr = start; ptr != NULL; ptr=ptr->GetNext()){
		  if (ptr->ComparePowers(m)) {
			  *ptr += m;
			  break;
		  } else if (ptr ->GetNext() == NULL) {
			  last_el = ptr;
		  }
	  }

	  if (last_el != NULL){
		last_el -> SetNext(new TMonomial(m));
		k++;
	  }
  }
  return *this;
}

TPolynomial &TPolynomial::operator-=(TMonomial &m)
{
  if (n != m.GetN())
    throw TException("Error");
  if (m.GetCoeff() == 0)
    return *this;
  if (start == NULL) {
    start = new TMonomial(m);
    start -> SetCoeff(start -> GetCoeff() * (-1));
	k++;
  }
  else
  {
	  TMonomial* last_el = NULL;
	  for ( TMonomial *ptr = start; ptr != NULL; ptr=ptr->GetNext()){
		  if (ptr->ComparePowers(m)) {
			  *ptr -= m;
			  break;
		  } else if (ptr ->GetNext() == NULL) {
			  last_el = ptr;
		  }
	  }

	  if (last_el != NULL){
		last_el -> SetNext(new TMonomial(m));
		last_el -> SetCoeff(last_el ->GetCoeff() * (-1));
		k++;
	  }
  }
  return *this;
}

bool TPolynomial::operator==(const TPolynomial &p)
{
  if (this->n != p.n)
    throw TException("Error");
  if (this->k != p.k)
    return false;
  for (TMonomial* src_ptr = start; src_ptr != NULL; src_ptr = src_ptr -> GetNext())
    for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr -> GetNext()){
		if (*src_ptr == *p_ptr) {
			break;
		} else if (p_ptr -> GetNext() == NULL) {
			return false;
		}
	}
  return true;
}

bool TPolynomial::operator!=(const TPolynomial &p)
{
  return !(*this == p);
}

TPolynomial TPolynomial::operator*(TPolynomial &p)
{
  if (n != p.n)
    throw TException("Error");
  TPolynomial tmp(n);

  for (TMonomial* src_ptr = start; src_ptr != NULL; src_ptr = src_ptr -> GetNext())
    for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr -> GetNext()) {
		tmp += (*src_ptr) * (*p_ptr);
	}
  return tmp;
}

TPolynomial TPolynomial::operator+(TPolynomial &p)
{
  if (n != p.n)
    throw TException("Error");
  TPolynomial tmp(p);

  for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr -> GetNext()) {
	tmp += *p_ptr;
  }

  return tmp;
}

TPolynomial TPolynomial::operator-(TPolynomial &p)
{
  if (n != p.n)
    throw TException("Error");
  TPolynomial tmp(p);

  for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr -> GetNext()) {
	tmp -= *p_ptr;
  }

  return tmp;
}

ostream& operator<<(ostream &ostr, TPolynomial& Tm)
{
  if (Tm.start == NULL)
	  ostr << "Empty";
  else {
	for (TMonomial* ptr = Tm.start; ptr != NULL; ptr = ptr -> GetNext()) {
		ostr << *ptr;
		if (ptr -> GetNext() != NULL)
			ostr << "+";
	}
  }
  return ostr;
}