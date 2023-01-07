#include "opMatch.h"
#include"operation.h"



opMatch::opMatch(controller* pCont) : operation(pCont)
{}

opMatch:: ~opMatch()
{
}

void opMatch::Execute() {
	Graph* pGR = pControl->getGraph();
	GUI* pGUI = pControl->GetUI();
	vector <shape*>selectedShapes = pGR->get_selected();
	if (selectedShapes.size() == 2)
	{
		if (selectedShapes[0]->get_type() == selectedShapes[1]->get_type())
		{
			selectedShapes[0]->SetVisible(false);
			selectedShapes[1]->SetVisible(false);
			pGR->setMatch(pGR->getMatch() + 3);
			pGUI->PrintMessage("CONGRATS!! the shapes matched. Your score is "+to_string(pGR->getMatch()));
		}
		else if (selectedShapes[0]->get_type() != selectedShapes[1]->get_type()) {
			pGR->unHide(pGUI);
			selectedShapes[0]->SetSelected(false);
			selectedShapes[1]->SetSelected(false);
			pGR->setMatch(pGR->getMatch() + 1);
			pGUI->PrintMessage("the shapes don't matched. Your score is " + to_string(pGR->getMatch()));
		}
	}
	else pGUI->PrintMessage("Select only two shapes");
	
}
