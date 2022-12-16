#include "opPen.h"
#include"operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"


opPen::opPen(controller* pCont) : operation(pCont)
{}

opPen:: ~opPen()
{}

void opPen::Execute() {

	GUI* pGUI = pControl->GetUI();
	color clr = pGUI->CreateColorPallete();
	pGUI->setCrntPenColor(clr);
}
