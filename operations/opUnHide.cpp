#include "opUnHide.h"
opUnHide::opUnHide(controller* pCont) : operation(pCont)
{}

opUnHide:: ~opUnHide()
{}

void opUnHide::Execute() {
	Graph* pGR = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGR->unHide(pGUI);
}