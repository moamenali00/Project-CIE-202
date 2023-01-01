#include "opAddStick.h"
#include"..\shapes\Shape.h"

opAddStick::opAddStick(controller* pCont) :operation(pCont)
{}
opAddStick::~opAddStick()
{}

//Execute the operation
void opAddStick::Execute()
{
	GUI* busy = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->StickI(busy);

}


