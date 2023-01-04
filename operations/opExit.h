#pragma once
#include "operation.h"

class controller; 

class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();
	virtual void Execute();
	virtual void Undo() {};


};

