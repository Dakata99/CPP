#include "Queue.h"

template <class T>
void Queue<T>::clear(void) { delete [] data; }

template <class T>
void Queue<T>::copy(const Queue<T>& other)
{
	
}

template <class T>
Queue<T>::Queue()
{
	size = 0;
	max_size = 1;
	data = new T[max_size];
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) { copy(other); }

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

template <class T>
bool Queue<T>::empty(void) const { return size == 0; }

template <class T>
const size_t Queue<T>::get_size(void) const { return size; }

template <class T>
const T& Queue<T>::front(void) const { assert(data != nullptr); return data[0]; }

template <class T>
const T& Queue<T>::back(void) const { assert(data != nullptr); return data[size - 1]; }

template <class T>
void Queue<T>::push(const T& elem)
{
	if (size + 1 >= max_size) resize(max_size * 2);
	//else if (max_size == size / 2) max_size /= 2;
	data[size++] = elem;
}

template <class T>
void Queue<T>::emplace(const T& elem) {}

template <class T>
void Queue<T>::pop(void) { assert(size > 0); size--; }

template <class T>
void Queue<T>::swap(Queue<T>&);

/* relational operators */
template <class T>
bool Queue<T>::operator==(const Queue<T>&) const;

template <class T>
void swap(Queue<T>&, Queue<T>&);

