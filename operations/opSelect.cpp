#include "opSelect.h"
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
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
		if (pGr->Getshape(C.x, C.y) != nullptr) {
			pGr->Getshape(C.x, C.y)->SetSelected(true);
			pGr->Getshape(C.x, C.y)->PrintInfo(pUI);
		}
		else { pUI->ClearStatusBar(); }
	}
	else {
		pGr->deSelect();
		if (pGr->Getshape(C.x, C.y) != nullptr) {
			pGr->Getshape(C.x, C.y)->SetSelected(true);
			pGr->Getshape(C.x, C.y)->PrintInfo(pUI);
		}
		else { pUI->ClearStatusBar(); }
	}




}