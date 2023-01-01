#include "opExit.h"
#include<fstream>
#include<iostream>
opExit::opExit(controller* pCont) : operation(pCont)
{}
opExit::~opExit()
{}

void opExit::Execute()
{
	GUI* UI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	UI->PrintMessage("Do you want to save?(Y/N):");
	if (tolower(UI->GetSrting()[0]) == 'y') {
		ofstream output;
		output.open("AutomaticSave.txt");
		output << (int)UI->getCrntDrawColor().ucRed << " " << (int)UI->getCrntDrawColor().ucGreen << " " << (int)UI->getCrntDrawColor().ucBlue << " ";
		if (UI->getFilledStatus()) {
			output << "fill";
			output << " " << (int)UI->getCrntFillColor().ucRed << " " << (int)UI->getCrntFillColor().ucGreen << " " << (int)UI->getCrntFillColor().ucBlue;;
		}
		else output << "nofill";
		output << " " << UI->getCrntPenWidth() << endl;
		pGr->Save(output);
		output.close();
		pGr->Clear();
	}

	else {
		pGr->Clear();;
	}



}