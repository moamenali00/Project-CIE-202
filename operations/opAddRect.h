#pragma once

#include "operation.h"

class opAddRect: public operation
{
public:
	opAddRect(controller *pCont);
	virtual ~opAddRect();
	
	virtual void Execute() ;
	virtual void Undo() {};
	
};

