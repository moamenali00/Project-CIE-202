#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class resize : public operation
{
public:
	resize(controller* pCont);
	virtual ~resize();
	virtual void Execute();
	//To undo this operation (code depends on operation type)
	virtual void Undo();

	//To redo this operation (code depends on operation type)
	virtual void Redo();
};
