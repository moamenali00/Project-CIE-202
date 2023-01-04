#pragma once
#include "operation.h"

class controller; 

class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();
	virtual void Execute();
	virtual void Undo() {};

};

