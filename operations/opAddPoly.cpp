#include "opAddPoly.h"
#include "..\shapes\Poly.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddPoly::opAddPoly(controller* pCont) :operation(pCont)
{}
opAddPoly::~opAddPoly()
{}

//Execute the operation
void opAddPoly::Execute()
{
	int vertices;


	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New polygone: enter number of vertices");
	//Read 1st corner and store in point P1
	string s = pUI->GetSrting();
	vertices = stoi(s);
	int* x = new int[vertices];
	int* y = new int[vertices];
	string msg = " click points of polygon as needed";

	pUI->PrintMessage(msg);
	for (int i = 0; i < vertices; i++) {
		pUI->GetPointClicked(x[i], y[i]);
	}





	pUI->ClearStatusBar();


	//Preapre all rectangle parameters
	GfxInfo PolyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	PolyGfxInfo.isFilled = false;	//default is not filled
	PolyGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Poly* R = new Poly(x, y, vertices, PolyGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
