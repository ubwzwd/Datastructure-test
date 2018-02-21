#ifndef ARRAY_H
#define ARRAY_H
#include "Object.h"
class Array
{
	Object **objects;
	int size; // Number of elements allocated
	int length; // Number of elements present
	void Grow(void);
public:
	Array(int size = 5);
	~Array();
	int GetLength();
	void Insert(int index, Object *object);
	Object *Delete(int index);
	Object *Get(int index);
	void Print();
};
#endif