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
			pGUI->PrintMessage("CONGRATS!! the shapes matched");
		}
		else pGUI->PrintMessage("the shapes don't match");
	}
	else pGUI->PrintMessage("Select only two shapes");
	
}
