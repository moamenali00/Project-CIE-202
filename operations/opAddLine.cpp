#include "opAddLine.h"
#include "..\shapes\Line.h"
opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first point");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();


	//Preapre all rectangle parameters
	GfxInfo LineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	if (P1.y < 70 || P2.y < 70)
	{
		pUI->PrintMessage("The line is out of the drawing area");
	}
	else if (P1.y > 650 || P2.y > 650) {
		pUI->PrintMessage("The line is out of the drawing area");
	}
	else {
		Line* R = new Line(P1, P2, LineGfxInfo);

		Graph* pGr = pControl->getGraph();

		pGr->Addshape(R);
	}

	

}
void opAddLine::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->Undo('c');
};
void opAddLine::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->Redo('c');
}
