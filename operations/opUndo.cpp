#include"opUndo.h"
opUndo::opUndo(controller* pCont) : operation(pCont)
{}
opUndo::~opUndo()
{}

void opUndo::Execute() {
	//pControl->Undo();
}