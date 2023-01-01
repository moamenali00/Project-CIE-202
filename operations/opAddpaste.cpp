#include "opAddpaste.h"
#include"..\operations\opAddpaste.h"

opAddpaste::opAddpaste(controller* pCont) :operation(pCont)
{}
opAddpaste::~opAddpaste()
{}

//Execute the operation
void opAddpaste::Execute()
{
	GUI* busy = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->paste(busy);

}