#pragma once

#include "operation.h"

class opAddTri : public operation
{
public:
	opAddTri(controller* pCont);
	virtual ~opAddTri();

	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};

};


