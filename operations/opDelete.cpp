#include "opDelete.h"
#include "..\shapes\Rect.h"
#include<iostream>
#include "..\controller.h"

#include "..\GUI\GUI.h"

opDelete::opDelete(controller* pCont) : operation(pCont)
{}
opDelete::~opDelete()
{}

void opDelete::Execute(){
	Graph* pGr = pControl->getGraph();
	pGr->Hide();

}
