#include <iostream>
#include <cstdlib>
#include "Deque.h"

Deque::Deque(int size = 5)
{
	this->size = size;
	length = 0;
	head = 0;
	objects = new Object*[size];
}

Deque::~Deque()
{
	delete objects;
}

int Deque::GetLength()
{
	return length;
}

void Deque::Grow()
{
	//double the size of the deque
	Object ** new_object_array;
	int new_size;
	int i;

	new_size = size * 2;
	new_object_array = new Object *[new_size];

	for (i = 0; i < size; i++)
	{
		new_object_array[i] = objects[(head + 1) % size];
	}

	delete objects;

	objects = new_object_array;
	size = new_size;
	head = 0;
}

void Deque::Insert(int index, Object * object)
{
	int i;

	if (index<0 || index>length)
	{
		std::cout << __FUNCTION__ << ": invalid index\n";
		exit(1);
	}

	if (length == size)
		Grow();
	if (index == 0 && head > 0)
		head--;
	else
	{
		for (i = length - 1; i >= index; i--)
			objects[(head + i + 1) % size] = object;
	}
	objects[(head + index) % size] = object;
	length++;
}