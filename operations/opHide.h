#pragma once
#include "operation.h"

class controller;

class opHide : public operation
{
public:
	opHide(controller* pCont);
	virtual ~opHide();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};