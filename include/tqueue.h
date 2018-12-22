#pragma once

#include "tstack.h"

template <typename QueueType>
class TQueue : public TStack <QueueType>
{
protected:
  int start;
  int count;
public:
  TQueue(int n = 0);
  TQueue(TQueue <QueueType> &Q);
  TQueue& operator=(const TQueue<QueueType>& queue);

  QueueType Get();
  void Put(QueueType Q);
  bool IsFull();
  bool IsEmpty();
  void PrintQueue();

  bool operator!=(const TQueue<QueueType>& queue) const;
  bool operator==(const TQueue<QueueType>& queue) const;
};
//-----------------------------------------------------------------
template <typename QueueType>
TQueue<QueueType>::TQueue(int n) : TStack<QueueType>(n)
{
  start = 0;
  count = 0;
}
//-----------------------------------------------------------------
template <typename QueueType>
TQueue<QueueType>::TQueue(TQueue<QueueType> &Q) : TStack<QueueType>(Q)
{
  start = Q.start;
  count = Q.count;
}
//-----------------------------------------------------------------
template <typename QueueType>
TQueue<QueueType>& TQueue<QueueType> ::operator=(const TQueue<QueueType>& queue)
{
  if ( this == &queue ) return *this;

  start = queue.start;
  count = queue.count;
  top = queue.top;

  if ( size != queue.size )
  {
    size = queue.size;
    delete[] memory;
    memory = new QueueType[size];
  }

  for ( int i = start; i <count+start; i++ )
  {
    memory[i % size] = queue.memory[i % size];
  }
  return *this;
}
//-----------------------------------------------------------------
template <typename QueueType>
void TQueue<QueueType>::Put(QueueType el)
{
  if (IsFull())
    throw TException("Queue is full.");
  else
  {
  memory[top] = el;
  top = ++top % size;
  count++;
  }
}
//-----------------------------------------------------------------
template <typename QueueType>
QueueType TQueue<QueueType>::Get()
{
  if (IsEmpty())
    throw TException("Queue is empty.");
  else
  {
    QueueType buf = memory[start];
    start = ++start % size;
    count--;

    return buf;
  }
}
//-----------------------------------------------------------------
template <typename QueueType>
bool TQueue<QueueType>::IsFull()
{
  return count == size ? true: false;
}
//-----------------------------------------------------------------
template <typename QueueType>
bool TQueue<QueueType>::IsEmpty()
{
  return count == 0 ? true: false;
}
//-----------------------------------------------------------------
template <typename QueueType>
bool TQueue<QueueType> ::operator==(const TQueue<QueueType>& queue) const
{

  if ( top != queue.top || size != queue.size ||
       count != queue.count || start !=queue.start )
    return false;
  for ( int i = start; i < count + start; i++ )
  {
    if ( memory[i % size] != queue.memory[i % size] )
      return false;
  }
  return true;
}
//-----------------------------------------------------------------
template <typename QueueType>
bool TQueue<QueueType> ::operator!=(const TQueue<QueueType>& queue) const
{
  return !( *this == queue );
}
