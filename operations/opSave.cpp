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
	UI->ClearStatusBar();
	output <<(int)UI->getCrntDrawColor().ucRed<<" "<<(int)UI->getCrntDrawColor().ucGreen<<" "<<(int)UI->getCrntDrawColor().ucBlue<<" ";
	if (UI->getFilledStatus()) { 
		output << "fill"; 
		output << " " << (int)UI->getCrntFillColor().ucRed<< " " << (int)UI->getCrntFillColor().ucGreen<< " " << (int)UI->getCrntFillColor().ucBlue;;
	}
	else output << "nofill";
	output << " " << UI->getCrntPenWidth()<<endl;
	Graph* pGr = pControl->getGraph();
	pGr->Save(output);
	output.close();
	}





