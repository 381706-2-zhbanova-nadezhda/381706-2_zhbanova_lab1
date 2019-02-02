#pragma once
#include <iostream>

using namespace std;

template <class ElementType>
class TElement
{
private:
  ElementType elem; //Значение
  TElement<ElementType>* next;//Указатель на след элемент
public:
  TElement(ElementType _elem = 0, TElement<ElementType>* _next = 0); //Конструктор с параметрами :1 - Значение элемента 2 - указатель на следующий элемент
  TElement(TElement<ElementType> &Elem); //Конструктор копирования

  ElementType GetElem(); //Получить эначение элемента
  TElement* GetNext(); //Получить указатель на следующий

  void Set(ElementType _elem); //Установить значение
  void SetNext(TElement<ElementType>* next); //Установить указатель
};

template <class ElementType>
TElement<ElementType>::TElement(ElementType _elem, TElement<ElementType>* _next)
{
  elem = _elem;
  if ( _next == 0 )
    next = 0;
  else
    next = _next;
}

template <class ElementType>
TElement<ElementType>::TElement(TElement<ElementType> &Elem)
{
  elem = Elem.elem;
  next = Elem.next;
}

template <class ElementType>
ElementType TElement<ElementType>::GetElem()
{
  return elem;
}

template <class ElementType>
TElement<ElementType>* TElement<ElementType>::GetNext()
{
  return next;
}

template <class ElementType>
void TElement<ElementType>::Set(ElementType _elem)
{
  elem = _elem;
}

template <class ElementType>
void TElement<ElementType>::SetNext(TElement<ElementType>* _next)
{
  next = _next;
}
