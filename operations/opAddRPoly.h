#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddRPoly : public operation
{
public:
	opAddRPoly(controller* pCont);
	virtual ~opAddRPoly();

	//Add rectangle to the controller
	virtual void Execute();

};


