#ifndef OBJECT_H
#define OBJECT_H
class Object
{
public:
	virtual void Print(void) = 0;
	virtual bool Compare(Object *) = 0;
	virtual ~Object() { }
};
#endif