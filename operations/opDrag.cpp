#include "opDrag.h"
opDrag::opDrag(controller* pCont) : operation(pCont)
{}
opDrag::~opDrag()
{}
void opDrag::Execute() {
	Point C, F, D,I;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	shape* S;
	C = pUI->ReturnPointClicked();
	I = C;
	int i = 0;
	S = pGr->Getshape(C.x, C.y);
	if (!pUI->getGUIMode())
		return;
	do {
		Sleep(6);
		i++;
		if (S != nullptr ) {
			pUI->ReturnMouseCoordinates(F);
			D.x = F.x - C.x;D.y = F.y - C.y;
			S->Move(D.x, D.y);
			S->PrintInfo(pUI);
			C = F;
			pControl->UpdateInterface();
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && i > 4) {
				pGr->Drag(S, I, F);
				return;
			}
		}
		else
			return;
	} while (true);


}
void opDrag::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->Undo('f');
};
void opDrag::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->Redo('f');
}