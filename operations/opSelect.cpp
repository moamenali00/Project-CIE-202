#include "opSelect.h"
#include "..\shapes\Rect.h"
#include<iostream>
#include "..\controller.h"

#include "..\GUI\GUI.h"

opSelect::opSelect(controller* pCont) : operation(pCont)
{}
opSelect::~opSelect()
{}

void opSelect::Execute()
{
	Point C;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->deSelect();
	C=pControl->P;
	if (pGr->Getshape(C.x, C.y) != nullptr) {
		pGr->Getshape(C.x, C.y)->SetSelected(true);
	}





}