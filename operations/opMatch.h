#pragma once
#include "operation.h"

class controller;

class opMatch : public operation
{
public:
	opMatch(controller* pCont);
	virtual ~opMatch();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};