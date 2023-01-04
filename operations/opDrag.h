#pragma once
#include "operation.h"

class controller;

class opDrag : public operation
{
public:
	opDrag(controller* pCont);
	virtual ~opDrag();
	virtual void Execute();
	virtual void Undo(){};
	virtual void Redo(){};
};