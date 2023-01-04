#pragma once
#include "operation.h"

class controller; 

class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual ~opDelete();
	virtual void Execute();
	virtual void Undo() ;
	virtual void Redo() ;
};