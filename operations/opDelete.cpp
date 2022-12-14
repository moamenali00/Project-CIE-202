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
void opDelete::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->Undo('d');
};
void opDelete::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->Redo('d');
}