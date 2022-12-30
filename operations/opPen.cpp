#include "opPen.h"
#include"operation.h"



opPen::opPen(controller* pCont) : operation(pCont)
{}

opPen:: ~opPen()
{}

void opPen::Execute() {

	Point P;
	GUI* pGUI = pControl->GetUI();
	color clr = pGUI->CreateColorPallete();
	P = pGUI->ReturnP();
	if (P.x < 70) {
		pGUI->ClearToolBar();
		pGUI->CreateDrawToolBar();

	}
	else if (P.x > 70 && P.x < 140)
	{

		pGUI->setCrntPenColor(pGUI->getDefaultDrawColor());
	}
	else
	{
		pGUI->setCrntPenColor(clr);
	}
}
