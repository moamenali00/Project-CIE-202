#include "opSelect.h"
#include<ctime>
#include<iostream>
opSelect::opSelect(controller* pCont) : operation(pCont)
{}
opSelect::~opSelect()
{}

void opSelect::Execute()
{
	Point C,F,D;double iT; static double fT=0;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	shape* S;
	C = pUI->ReturnPointClicked();
	iT = clock();
	int i = 0;
	if (iT - fT <= 300) {
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
	
	else if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
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
	fT = clock();



}