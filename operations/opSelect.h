#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();
	virtual void Execute();

};

