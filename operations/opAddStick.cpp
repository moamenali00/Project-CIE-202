#include "opAddStick.h"
#include"..\shapes\Shape.h"
#include<iostream>
opAddStick::opAddStick(controller* pCont) :operation(pCont)
{}
opAddStick::~opAddStick()
{}

//Execute the operation
void opAddStick::Execute()
{
	Graph* pGr = pControl->getGraph();
	pGr->StickI();

}


