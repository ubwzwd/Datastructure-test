#ifndef INTEGER_H
#define INTEGER_H
#include "Object.h"
class Integer : public Object
{
public:
	int value;
	Integer(int value);
	void Print();
};
#endif