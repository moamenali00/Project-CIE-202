#pragma once
#include "operation.h"

class controller; 

class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};

