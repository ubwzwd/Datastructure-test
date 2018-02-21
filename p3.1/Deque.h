#ifndef DEQUE_H_
#define DEQUE_H_

#include "Object.h"

class Deque
{
	Object **objects;
	int size;
	int length;

	void Grow();
	int head;
public:
	Deque(int size = 5);
	virtual ~Deque();

	int GetLength();
	void Insert(int index, Object * object);
	Object * Delete(int index);
	Object * Get(int index);
	void Print();
};

#endif

