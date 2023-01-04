#pragma once
#include "operation.h"

class controller; 

class opLoad : public operation
{
public:
	opLoad(controller* pCont);
	virtual ~opLoad();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};

};

