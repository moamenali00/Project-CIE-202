#include "opAddRPoly.h"
#include "..\shapes\Rpoly.h"


opAddRPoly::opAddRPoly(controller* pCont) :operation(pCont)
{}
opAddRPoly::~opAddRPoly()
{}

//Execute the operation
void opAddRPoly::Execute()
{
	int vertices;


	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New polygone: enter number of vertices");
	//Read 1st corner and store in point P1
	string s = pUI->GetSrting();
	vertices = stoi(s);
	pUI->ClearStatusBar();
	Point center, vertex;
	pUI->PrintMessage("New polygone: enter the center");
	pUI->GetPointClicked(center.x, center.y);
	pUI->ClearStatusBar();
	pUI->PrintMessage("enter the vertex");
	pUI->GetPointClicked(vertex.x, vertex.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo PolyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	PolyGfxInfo.isFilled = pUI->getFilledStatus();	//default is not filled
	PolyGfxInfo.isSelected = false;	//defualt is not selected

	int rad;
	rad = sqrt(((center.x - vertex.x) * (center.x - vertex.x)) + ((center.y - vertex.y) * (center.y - vertex.y)));

	if (center.y < 70 || center.y - rad < 70)
	{
		pUI->PrintMessage("The Shape is out of the drawing area");
	}
	else if (center.y > 650 || center.y + rad > 650) {
		pUI->PrintMessage("The Shape is out of the drawing area");
	}
	else {

		//Create a rectangle with the above parameters
		Rpoly* R = new Rpoly(center, vertex, vertices, PolyGfxInfo);
		//R->set_x_y();


		//Get a pointer to the graph
		Graph* pGr = pControl->getGraph();

		//Add the rectangle to the list of shapes
		pGr->Addshape(R);
	}
}
void opAddRPoly::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->Undo('c');
};
void opAddRPoly::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->Redo('c');
}