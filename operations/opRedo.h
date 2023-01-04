#include "operation.h"

class controller;

class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();
	virtual void Execute();
	virtual void Undo() {};
	virtual void Redo() {};
};

