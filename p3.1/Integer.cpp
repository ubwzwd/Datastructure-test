#include <iostream>
#include "Integer.h"
Integer::Integer(int value)
{
	this->value = value;
}
void Integer::Print()
{
	std::cout << value << std::endl;
}