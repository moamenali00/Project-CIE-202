#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
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
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsVisible())
			shapePointer->Draw(pUI);
	}
}
void Graph::deSelect() {
	for (auto shapePointer : shapesList) {
		shapePointer->SetSelected(false);
	}
}

void Graph::setColor(shape* pShp) 
{
	GUI* pGUI;
	color clr = pGUI->getCrntFillColor();
	pShp->ChngFillClr(clr);
}

void Graph::Hide() {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->SetVisible(false);
		}
	}
}
void Graph::StickI()
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->stickimages();
		}
	}
}
void Graph::Clear() {
	for (auto shapePointer : shapesList) {
		delete shapePointer;
		shapePointer=nullptr;
	}
}
void Graph::Save(ofstream& outfile){
	int size = shapesList.size();
	int id = 0;
	outfile << size<<endl;
	for (int z = 0;z < size;z++) {
		if (shapesList[z]->IsVisible()) {
			shape* shape = shapesList[z];
			shape->Save(outfile, ++id);	
			outfile << endl;
		}
		


	}

}

shape* Graph::Getshape(int x, int y) const
{
	{
		for (int i = shapesList.size()-1;i>=0;i--) {
			if (shapesList[i] != nullptr && shapesList[i]->IsVisible())
				if (shapesList[i]->CheckSelect(x, y)) {
					return shapesList[i];
				}
		}
		


		}
		return nullptr;
	}
