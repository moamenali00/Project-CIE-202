#include "opSelect.h"
#include<ctime>
#include<iostream>
opSelect::opSelect(controller* pCont) : operation(pCont)
{}
opSelect::~opSelect()
{}

void opSelect::Execute()
{
	Point C;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	C = pUI->ReturnPointClicked();
	shape* S= pGr->Getshape(C.x, C.y);
	if (pUI->getGUIMode()) {
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
			if (S != nullptr) {
				S->SetSelected(true);
				S->PrintInfo(pUI);
			}
			else { pUI->ClearStatusBar(); }
		}
		else {
			pGr->deSelect();
			if (S != nullptr) {
				S->SetSelected(true);
				S->PrintInfo(pUI);
			}
			else { pUI->ClearStatusBar(); }
		}
	}
	else {
		if (S != nullptr) {
			S->SetSelected(true);
			pUI->PrintMessage("Shape is selected");
		}
		else {
			pGr->deSelect();
			pUI->ClearStatusBar();
		}
	}

}