#pragma once
#include "operation.h"

class controller;

class opDuplicate : public operation
{
public:
	opDuplicate(controller* pCont);
	virtual ~opDuplicate();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};