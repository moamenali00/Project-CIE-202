#include "opStart.h"
#include"operation.h"



opStart::opStart(controller* pCont) : operation(pCont)
{}

opStart:: ~opStart()
{
}

void opStart::Execute() {
	Graph* pGR = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGR->duplicate_shape(pGUI);
	pGR->scramble_image();
	pGR->pHide(pGUI);
	pGUI->PrintMessage("Start the game!! you current score is 0");
}
