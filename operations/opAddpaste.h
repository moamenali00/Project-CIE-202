#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opAddpaste : public operation
{
public:
	opAddpaste(controller* pCont);
	virtual ~opAddpaste();
	virtual void Execute();
	virtual void Undo() {};

};
