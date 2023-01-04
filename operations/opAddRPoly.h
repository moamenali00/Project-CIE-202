#pragma once

#include "operation.h"

class opAddRPoly : public operation
{
public:
	opAddRPoly(controller* pCont);
	virtual ~opAddRPoly();

	virtual void Execute();
	virtual void Undo() {};

};


