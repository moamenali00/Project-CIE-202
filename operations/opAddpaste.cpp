#include "opAddpaste.h"
#include"..\operations\opAddpaste.h"

opAddpaste::opAddpaste(controller* pCont) :operation(pCont)
{}
opAddpaste::~opAddpaste()
{}

//Execute the operation
void opAddpaste::Execute()
{
	int x, y;
	GUI* busy = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	busy->GetPointClicked(x, y);
	pGr->paste(x, y);
	
}