#include "opDrag.h"

opDrag::opDrag(controller* pCont) : operation(pCont)
{}
opDrag::~opDrag()
{}

void opDrag::Execute() {
	Point Pi,Distance;
	Point Pf;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(Pi.x, Pi.y);
	pGr->deSelect();
	pGr->Getshape(Pi.x, Pi.y)->SetSelected(true);
	while (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
		pUI->ReturnMouseCoordinates(Pf);
		Distance.x = Pf.x - Pi.x;
		Distance.y = Pf.y - Pi.x;
		pGr->Move(Distance);	
		pControl->UpdateInterface();
	}
	
}