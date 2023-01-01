#include "opExit.h"
#include<fstream>
opExit::opExit(controller* pCont) : operation(pCont)
{}
opExit::~opExit()
{}

void opExit::Execute()
{
	ofstream output;
	output.open("output.txt");
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->Save(output);
	output.close();





}