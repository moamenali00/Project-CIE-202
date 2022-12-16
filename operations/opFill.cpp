#include "opFill.h"
#include"operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"


opFill::opFill(controller* pCont) : operation(pCont)
{}

opFill:: ~opFill()
{}

void opFill::Execute() {
	
	GUI* pGUI = pControl->GetUI();
	color clr= pGUI->CreateColorPallete();
	pGUI->setCrntFillColor(clr);
	pGUI->setFilledStatus(true);
}
