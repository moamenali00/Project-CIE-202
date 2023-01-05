#include "opHide.h"
#include"operation.h"



opHide::opHide(controller* pCont) : operation(pCont)
{}

opHide:: ~opHide()
{}

void opHide::Execute() {
	Graph* pGR = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGR->pHide(pGUI);
}
