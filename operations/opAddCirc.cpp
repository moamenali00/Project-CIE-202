#include "opAddCirc.h"
#include "..\shapes\Circ.h"
opAddCirc::opAddCirc(controller* pCont) :operation(pCont)
{}
opAddCirc::~opAddCirc()
{}

//Execute the operation
void opAddCirc::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at first point of diameter");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point of diameter is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();


	//Preapre all rectangle parameters
	GfxInfo CircGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircGfxInfo.FillClr = pUI->getCrntFillColor();
	CircGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CircGfxInfo.isFilled = false;	//default is not filled
	CircGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Circ* R = new Circ(P1, P2, CircGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
