#include <iostream>

#include <circ_buffer.h>

template <class T>
CircularBuffer<T>::
CircularBuffer(int n_)
  : _maxElems(n_), _head(0), _tail(0), _numElems(0)
{
  _arrT = new T[_maxElems];
}

template <class T>
CircularBuffer<T>::
~CircularBuffer()
{
  if (_arrT!=0) delete [] _arrT;
}

template<class T>
CircularBuffer<T>::
CircularBuffer(const CircularBuffer& t_)
{
  std::cout << "Copy Constructor" << std::endl;
}


template<class T>
CircularBuffer<T>& CircularBuffer<T>::
operator=(const CircularBuffer& t_)
{
  std::cout << "Assignment Operator" << std::endl;
  return *this;
}


template<class T>
CircularBuffer<T>::
CircularBuffer(CircularBuffer&& t_)
{
  if (_arrT!=0) delete [] _arrT;
  _arrT = std::move(t_._arrT);
  _maxElems = t._maxElems;
  _head = t_._head;
  _tail = t._tail;
  _numElems = t_._numElems;
}

template <class T>
bool CircularBuffer<T>::
empty(void) const
{
  if (std::load(_head) == std::load(_tail))
    return true;
  else
    return false;
}


template <class T>
bool CircularBuffer<T>::
full(void) const
{
  if ((std::load(_head)+1)%_maxElems == std::load(_tail))
    return true;
  else
    return false;
}

template <class T>
void CircularBuffer<T>::
push(const T& t_)
{

