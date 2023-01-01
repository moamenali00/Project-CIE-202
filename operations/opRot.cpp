#include "opRot.h"
#include"operation.h"



opRot::opRot(controller* pCont) : operation(pCont)
{}

opRot:: ~opRot()
{}

void opRot::Execute() {
	Graph* pGr = pControl->getGraph();
	pGr->Rotate();



}