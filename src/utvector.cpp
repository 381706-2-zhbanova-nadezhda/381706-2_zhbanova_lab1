#include "utvector.h"

template <class ValType>
TVector<ValType>::TVector(int s, int si):Size(s),StartIndex(si)
{
	if((s>MAX_VECTOR_SIZE)||(s<0)) throw 1;
	else if((si>MAX_VECTOR_SIZE)||(si<0)) throw 1;
	else
	pVector = new ValType [s];
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size=v.Size;
	StartIndex=v.StartIndex;
	pVector = new ValType[Size];
	for (int i=0;i<Size;i++){pVector[i]=v.pVector[i];}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete [] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < StartIndex || pos >= StartIndex + Size) {
		throw 3;
	}
	return pVector[pos-StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if(Size!=v.Size)return false;
	else if(StartIndex!=v.StartIndex) return false;
	else {
		for (int i=0;i<Size;i++){
			if (pVector[i]!=v.pVector[i]){
				return false;
			}
		}

	return true;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if(Size!=v.Size)return true;
	else if(StartIndex!=v.StartIndex) return true;
	else {
		for (int i=0;i<Size;i++){
			if (pVector[i]!=v.pVector[i]){
				return true;
			}
		}

	return false;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if(&v!=this){
		Size=v.Size;
		StartIndex = v.StartIndex;
		
		delete [] pVector;
		pVector = new ValType [Size];

		for (int i=0;i<Size;i++) pVector[i]=v.pVector[i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector <ValType> buf(Size,StartIndex);
	
	for(int i=0;i<Size;i++){
		buf.pVector[i]=pVector[i]+val;}

	return buf;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector <ValType> buf(Size,StartIndex);
	
	for(int i=0;i<Size;i++){
		buf.pVector[i]=pVector[i]-val;}

	return buf;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector <ValType> buf(Size,StartIndex);
	
	for(int i=0;i<Size;i++) buf.pVector[i]=pVector[i]*val;

	return buf;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size || StartIndex != v.StartIndex) {
		throw 4;
	}

	TVector<ValType> temp(Size, StartIndex);

	for (int i = 0; i < Size; i++) {
		temp.pVector[i] = pVector[i] + v.pVector[i];
	}

	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size || StartIndex != v.StartIndex) {
		throw 4;
	}

	TVector<ValType> temp(Size, StartIndex);

	for (int i = 0; i < Size; i++) {
		temp.pVector[i] = pVector[i] - v.pVector[i];
	}

	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (Size != v.Size || StartIndex != v.StartIndex) {
		throw 4;
	}

	ValType skalar = pVector[0]*v.pVector[0];
	for (int i=1;i<Size;i++){
		skalar+=(pVector[i]*v.pVector[i]);
	}
	return skalar;
} /*-------------------------------------------------------------------------*/