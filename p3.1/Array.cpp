#include <iostream>
#include <cstdlib>
#include "Array.h"

Array::Array(int size)
{
	this->size = size;
	length = 0;
	objects = new Object*[size];
}

Array::~Array()
{
	delete objects;
}

int Array::GetLength()
{
	return length;
}

void Array::Grow()
{
	Object **new_object_array;
	int new_size;
	int i;
	// Allocate new space
	new_size = size * 2;
	new_object_array = new Object*[new_size];
	// Copy objects
	for (i = 0; i < size; i++)
		new_object_array[i] = objects[i];
	// Assign new values
	delete objects;
	objects = new_object_array;
	size = new_size;
}

void Array::Insert(int index, Object *object)
{
	int i;
	// Check index
	if (index < 0 || index > length)
	{
		std::cerr << __FUNCTION__ << ": invalid index" << std::endl;
		exit(1);
	}
	// Grow if necessary
	if (length == size)
		Grow();// Shift elements after index
	for (i = length - 1; i >= index; i--)
		objects[i + 1] = objects[i];
	// Insert new element
	objects[index] = object;
	length++;
}

Object *Array::Delete(int index)
{
	int i;
	Object *object;
	// Check index
	if (index < 0 || index >= length)
	{
		std::cerr << __FUNCTION__ << ": invalid index" << std::endl;
		exit(1);
	}
	// Shift element after index
	object = objects[index];
	for (i = index + 1; i < length; i++)
		objects[i - 1] = objects[i];
	// Return element
	length--;
	return object;
}

Object *Array::Get(int index)
{
	// Check index
	if (index < 0 || index >= length)
	{
		std::cerr << __FUNCTION__ << ": invalid index" << std::endl;
		exit(1);
	}
	// Return element
	return objects[index];
}

void Array::Print(void)
{
	int i;
	for (i = 0; i < length; i++)
		objects[i]->Print();
}