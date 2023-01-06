#include "controller.h"
#include "operations\opAddRect.h"
#include"operations\opAddSquare.h"
#include "operations\opAddLine.h"
#include "operations\opAddCirc.h"
#include "operations\opAddTri.h"
#include "operations\opAddPoly.h"
#include "operations\opSelect.h"
#include"operations\opDelete.h"
#include"operations\opSave.h"
#include"operations\opFill.h"
#include "operations\opPen.h"
#include"operations\opLoad.h"
#include"operations\opAddRPoly.h"
#include"operations\opExit.h"
#include"operations\opAddStick.h"
#include"operations\opAddcopy.h"
#include"operations\opAddpaste.h"
#include"operations\opRedo.h"
#include"operations\opUndo.h"
#include"operations\resize.h"
#include"operations/opRot.h"
#include"operations/opDrag.h"
#include"operations/opAddscramble_image.h"
#include"operations/opDuplicate.h"
#include"operations/opHide.h"
#include"operations/opMatch.h"
#include"operations/opUnHide.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;                      
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	static int Tf = 0;int Ti=clock();
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;
		case STICKIMAGE:
			pOp = new opAddStick(this);
			break;
		case TO_SCRAMBLE:
			pOp = new opAddscramble_image(this);
			break;
		case RESIZE:
			pOp = new resize(this);
			break;
		case TO_PASTE:
			pOp = new opAddpaste(this);
			break;
		case TO_COPY:
			pOp = new opAddcopy(this);
			break;

		case DRAW_SQUARE:
			pOp = new opAddSquare(this);
			break;
		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;
		case DRAW_TRI:
			pOp = new opAddTri(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCirc(this);
			break;
		case DRAW_POLY:
			pOp = new opAddRPoly(this);
			break;
		case DRAW_IPOLY:
			pOp = new opAddPoly(this);
			break;
		case SAVE:
			pOp = new opSave(this);
			break;
		case DEL:
			pOp = new opDelete(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new opFill(this);
			break;
		case CHNG_DRAW_CLR:
			pOp = new opPen(this);
			break;
		case DRAWING_AREA:
			if (Ti - Tf < 300) {
				pOp = new opDrag(this);
			}
			else
				pOp = new opSelect(this);
			break;
		case LOAD:
			pOp = new opLoad(this);
			break;
		case ROTATE:
			pOp = new opRot(this);
			break;
		case EXIT:
			pOp = new opExit(this);
			break;
		case DUPLICATE_GRAPH:
			pOp = new opDuplicate(this);
			break;

		case STATUS:	//a click on the status bar ==> no operation
			break;

		case TO_PLAY:
			pGUI->CreatePlayToolBar();
			break;

		case TO_DRAW:
			pGUI->CreateDrawToolBar();
			break;
		case HIDE:
			pOp = new opHide(this);
			break;
		case UNDO:
			pOp = new opUndo(this);
			break;
		case REDO:
			pOp = new opRedo(this);
			break;
	
		case MATCH:
			pOp = new opUnHide(this);
			break;

	
	}
	Tf = clock();
	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}

//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	while (!undo.empty()) {
		operation* p = undo.top();
		undo.pop();
		delete p;
	}
	while (!redo.empty()) {
		operation* p = redo.top();
		redo.pop();
		delete p;
	}
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller ::Undo() {
	if (!(undo.empty())) {
		undo.top()->Undo();
		redo.push(undo.top());
		undo.pop();
	}
}
void controller :: Redo() {
	if (!(redo.empty())) {
		redo.top()->Redo();
		undo.push(redo.top());
		redo.pop();
	}
}
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		//3. Execute the created operation
		if (pOpr)
		{
			if (dynamic_cast<opDelete*> (pOpr))
			{
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<resize*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opDrag*>(pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddRect*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddCirc*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddPoly*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddRPoly*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddTri*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddLine*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else if (dynamic_cast<opAddSquare*> (pOpr)) {
				undo.push(pOpr);
				pOpr->Execute();
			}
			else {
				pOpr->Execute();
				delete pOpr;
				pOpr = nullptr;
			}
		}
		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}