#pragma once
#include "operation.h"

class controller;

class opPen : public operation
{
public:
	opPen(controller* pCont);
	virtual ~opPen();
	virtual void Execute();
	virtual void Undo() {};
};