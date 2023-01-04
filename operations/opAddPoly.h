#pragma once

#include "operation.h"

class opAddPoly : public operation
{
public:
	opAddPoly(controller* pCont);
	virtual ~opAddPoly();

	virtual void Execute();
	virtual void Undo() {};

};


