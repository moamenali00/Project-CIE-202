#pragma once
#include "operation.h"

class controller;

class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};