#include"opSave.h"
#include"operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"fstream"
opSave::opSave(controller* pCont) : operation(pCont)
{}
opSave::~opSave()
{}

void opSave::Execute()
{
	ofstream output;
	output.open("output.txt");
	Graph* pGr = pControl->getGraph();
	pGr->Save(output);
	output.close();
	}





