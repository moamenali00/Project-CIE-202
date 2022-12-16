#include "opDelete.h"

opDelete::opDelete(controller* pCont) : operation(pCont)
{}
opDelete::~opDelete()
{}

void opDelete::Execute(){
	Graph* pGr = pControl->getGraph();
	pGr->Hide();

}
