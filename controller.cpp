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
#include"operations/opAddscramble_image.h"
#include"operations/opDrag.h"
#include"operations/opDuplicate.h"

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
	
	}

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
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
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
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}
		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}