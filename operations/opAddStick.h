#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddStick : public operation
{
public:
	opAddStick(controller* pCont);
	virtual ~opAddStick();

	//Add rectangle to the controller
	virtual void Execute();

};