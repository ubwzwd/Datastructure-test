#include <iostream>
#include "Integer.h"
Integer::Integer(int value)
{
	this->value = value;
}
void Integer::Print(void)
{
	std::cout << value << std::endl;
}
bool Integer::Compare(Object *other)
{
	return value < dynamic_cast<Integer *>(other)->value;
}