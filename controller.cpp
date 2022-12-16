#include "controller.h"
#include "operations\opAddRect.h"
#include"operations\opAddSquare.h"
#include "operations\opAddLine.h"
#include "operations\opAddCirc.h"
#include "operations\opAddTri.h"
#include "operations\opSelect.h"
#include"operations\opDelete.h"
#include"operations\opSave.h"
#include"operations\opFill.h"
#include "operations\opPen.h"


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
		
		case EXIT:
			///create Exitoperation here
			
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