#include "opDrag.h"

opDrag::opDrag(controller* pCont) : operation(pCont)
{}
opDrag::~opDrag()
{}
void opDrag::Execute() {
	Point C, F, D;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	shape* S;
	C = pUI->ReturnPointClicked();
	int i = 0;
	do {
		Sleep(10);
		S = pGr->Getshape(C.x, C.y);
		i++;
		if (S != nullptr) {
			pUI->ReturnMouseCoordinates(F);
			D.x = F.x - C.x;D.y = F.y - C.y;
			S->Move(D.x, D.y);
			C = F;
			pControl->UpdateInterface();
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && i > 4)
				return;
		}
	} while (true);


}