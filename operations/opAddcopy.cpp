#include "opAddcopy.h"
#include"..\operations\opAddcopy.h"

opAddcopy::opAddcopy(controller* pCont) :operation(pCont)
{}
opAddcopy::~opAddcopy()
{}

//Execute the operation
void opAddcopy::Execute()
{
	Graph* pGr = pControl->getGraph();
	pGr->copy();

}