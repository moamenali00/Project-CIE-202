#pragma once
#include "operation.h"
class controller;

class opUnHide : public operation
{
public:
	opUnHide(controller* pCont);
	virtual ~opUnHide();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};

