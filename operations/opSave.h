#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();
	virtual void Execute();

};

