#include"opSave.h"
#include"fstream"


opSave::opSave(controller* pCont) : operation(pCont)
{}
opSave::~opSave()
{}

void opSave::Execute()
{
	GUI* UI = pControl->GetUI();
	UI->PrintMessage("Enter the file name(relative address)");
	ofstream output;
	output.open(UI->GetSrting());
	Graph* pGr = pControl->getGraph();
	pGr->Save(output);
	output.close();
	}





