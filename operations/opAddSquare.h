#pragma once

#include "operation.h"

class opAddSquare : public operation
{
public:
	opAddSquare(controller* pCont);
	virtual ~opAddSquare();

	virtual void Execute();
	virtual void Undo() ;
	virtual void Redo() ;

};

