#include "opAddpaste.h"
#include"..\operations\opAddpaste.h"

opAddpaste::opAddpaste(controller* pCont) :operation(pCont)
{}
opAddpaste::~opAddpaste()
{}

//Execute the operation
void opAddpaste::Execute()
{
	int x, y, n;
	GUI* busy = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	do 
	{
		busy->GetPointClicked(x, y);
		pGr->paste(x, y, n);
		pControl->UpdateInterface();
	} while (n != 0);

}