#pragma once
#include <cassert>

template <class T>
class Queue
{
private:
	T* data;
	size_t size, max_size;
	
private:
	void clear(void);
	void copy(const Queue<T>&);
	
public:
	Queue();
	Queue(const Queue<T>&);
	~Queue();
	
	Queue<T>& operator= (const Queue<T>&);
	
	bool empty(void) const noexcept;
	const size_t size(void) const noexcept; 
	const T& front(void) const;
	const T& back(void) const;
	void push(const T&);
	void emplace(const T&);
	void pop(void);
	void swap(Queue<T>&);
	
	/* relational operators */
	bool operator== (const Queue<T>&) const;
	friend void swap(Queue<T>&, Queue<T>&);
};

#include "Queue.h"

