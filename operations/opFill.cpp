#include "opFill.h"
#include"operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <iostream>
using namespace std;

opFill::opFill(controller* pCont) : operation(pCont)
{}

opFill:: ~opFill()
{}

void opFill::Execute() {
	
	GUI* pGUI = pControl->GetUI();
	color clr= pGUI->CreateColorPallete();
	GUI* pGUI3 = pControl->GetUI();
	pGUI3->setCrntFillColor(clr);
}
