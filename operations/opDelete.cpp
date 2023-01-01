#include "opDelete.h"

opDelete::opDelete(controller* pCont) : operation(pCont)
{}
opDelete::~opDelete()
{}

void opDelete::Execute(){
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->Hide();
	pUI->ClearStatusBar();
}
