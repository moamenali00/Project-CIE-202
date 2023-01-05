#include"opDuplicate.h"
#include "operation.h"

opDuplicate::opDuplicate(controller* pCont) : operation(pCont)
{}

opDuplicate:: ~opDuplicate()
{}

void opDuplicate::Execute() {
	Graph* pGr = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGr->duplicate_shape(pGUI);
}
