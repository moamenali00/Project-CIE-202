#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual ~opDelete();
	virtual void Execute();
};