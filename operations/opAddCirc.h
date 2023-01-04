#pragma once

#include "operation.h"

class opAddCirc : public operation
{
public:
	opAddCirc(controller* pCont);
	virtual ~opAddCirc();

	virtual void Execute();
	virtual void Undo() {};
};


