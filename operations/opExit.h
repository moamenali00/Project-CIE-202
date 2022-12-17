#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();
	virtual void Execute();

};

