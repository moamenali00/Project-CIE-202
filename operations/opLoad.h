#pragma once
#include "operation.h"

class controller; //forward class declaration

//Add Rectangle operation class
class opLoad : public operation
{
public:
	opLoad(controller* pCont);
	virtual ~opLoad();
	virtual void Execute();

};

