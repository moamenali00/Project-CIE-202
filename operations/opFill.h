#pragma once
#include "operation.h"

class controller;

class opFill : public operation
{
public:
	opFill(controller* pCont);
	virtual ~opFill();
	virtual void Execute();
};