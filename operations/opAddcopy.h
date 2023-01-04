#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opAddcopy : public operation
{
public:
	opAddcopy(controller* pCont);
	virtual ~opAddcopy();
	virtual void Execute();

};
