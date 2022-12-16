#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddPoly : public operation
{
public:
	opAddPoly(controller* pCont);
	virtual ~opAddPoly();

	//Add rectangle to the controller
	virtual void Execute();

};


