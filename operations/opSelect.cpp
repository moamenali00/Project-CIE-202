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
	Point P;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->deSelect();
	pUI->GetPointClicked(P.x, P.y);
	if (pGr->Getshape(P.x, P.y) != nullptr) {
		pGr->Getshape(P.x, P.y)->SetSelected(true);
	}





}