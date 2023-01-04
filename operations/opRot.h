#pragma once
#include "operation.h"

class controller;

class opRot : public operation
{
public:
	opRot(controller* pCont);
	virtual ~opRot();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};