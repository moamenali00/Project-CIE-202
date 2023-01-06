#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opAddscramble_image : public operation
{
public:
	opAddscramble_image(controller* pCont);
	virtual ~opAddscramble_image();
	virtual void Execute();
	//To undo this operation (code depends on operation type)
	virtual void Undo(){};

	//To redo this operation (code depends on operation type)
	virtual void Redo(){};
};
