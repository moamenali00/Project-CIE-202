#pragma once

#include "operation.h"

class opAddStick : public operation
{
public:
	opAddStick(controller* pCont);
	virtual ~opAddStick();

	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};


};