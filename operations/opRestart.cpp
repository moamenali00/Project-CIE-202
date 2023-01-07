#include "opRestart.h"
#include"operation.h"



opRestart::opRestart(controller* pCont) : operation(pCont)
{}

opRestart:: ~opRestart()
{
}

void opRestart::Execute() {
	
	Graph* pGR = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	pGR->Restart();
	pGR->scramble_image();
	pGR->pHide(pGUI);
	pGUI->PrintMessage("Start the game!! you current score is 0");

}
