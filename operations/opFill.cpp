#include "opFill.h"
#include"operation.h"



opFill::opFill(controller* pCont) : operation(pCont)
{}

opFill:: ~opFill()
{}

void opFill::Execute() {
	Point P;
	GUI* pGUI = pControl->GetUI();
	//pGUI->GetPointClicked(P.x, P.y);
	color clr= pGUI->CreateColorPallete();
	P = pGUI->ReturnP();
	if (P.x < 70) {
		pGUI->ClearToolBar();
		pGUI->CreateDrawToolBar();

	}
	else if (P.x > 70 && P.x < 140)
	{

		pGUI->setFilledStatus(false);
		//setCrntPenColor(Default_Drawcolor);
	}
	else
	{
		pGUI->setCrntFillColor(clr);
		pGUI->setFilledStatus(true);
	}
}
