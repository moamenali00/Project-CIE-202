#include "operation.h"

class controller;

class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();
	virtual void Execute();
	virtual void Undo() {};

};

