#pragma once
#include "operation.h"

class controller;

class opRestart : public operation
{
public:
	opRestart(controller* pCont);
	virtual ~opRestart();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};