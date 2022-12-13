#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsHidden())
			shapePointer->Draw(pUI);
	}
}

void Graph::deSelect() {
	for (auto shapePointer : shapesList) {
		shapePointer->SetSelected(false);
	}
}
void Graph::Hide() {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->SetHidden(false);
		}
	}
}


shape* Graph::Getshape(int x, int y) const
{
	{
		for (auto shapePointer : shapesList) {
			if (shapePointer != nullptr&&shapePointer->IsHidden())
				if (shapePointer->CheckSelect(x, y)) {
					return shapePointer;
				}



		}
		return nullptr;
	}
}