#include "opExit.h"
#include<fstream>
opExit::opExit(controller* pCont) : operation(pCont)
{}
opExit::~opExit()
{}

void opExit::Execute()
{
	GUI* UI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	ofstream output;
	UI->PrintMessage("Do you want to save?(Y/N):");
	if (tolower(UI->GetSrting()[0]) == 'y') {
		output << (int)UI->getCrntDrawColor().ucRed << " " << (int)UI->getCrntDrawColor().ucGreen << " " << (int)UI->getCrntDrawColor().ucBlue << " ";
		if (UI->getFilledStatus()) {
			output << "fill";
			output << " " << (int)UI->getCrntFillColor().ucRed << " " << (int)UI->getCrntFillColor().ucGreen << " " << (int)UI->getCrntFillColor().ucBlue;;
		}
		else output << "nofill";
		output << " " << UI->getCrntPenWidth() << endl;
		Graph* pGr = pControl->getGraph();
		pGr->Save(output);
		output.close();
		output.open("output.txt");
		pGr->Save(output);
		output.close();
	}

	else
		return;




}