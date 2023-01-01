#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
Graph::Graph()
{
	selectedShape = nullptr;
	copied = nullptr;
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
void Graph::Draw(GUI* pUI) 
{
	size = 0;
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
<<<<<<< HEAD
		if (shapePointer->IsVisible())
		{
			shapePointer->Draw(pUI);
			if (shapePointer->iswithimage())
			{
				shapePointer->stickimages(pUI);
			}
=======
		if (shapePointer->IsVisible()) {
			shapePointer->Draw(pUI);
			size++;
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
		}
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
void Graph::StickI(GUI*G)
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->stickimages(G);
		}
	}
}
<<<<<<< HEAD
void Graph::copy()
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			copied = shapePointer->copy();
			return;
		}
	}
}
void Graph::paste(GUI* G)
{
	int x, y;
	G->GetPointClicked(x, y);
	copied->paste(x, y);
	shapesList.push_back(copied);
}
=======
void Graph::Rotate() {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->RotateShape();
		}
	}
 }

>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
void Graph::Clear() {
	for (auto shapePointer : shapesList) {
		delete shapePointer;
		shapePointer=nullptr;
	}
}
void Graph::Save(ofstream& outfile){
	int id = 0;
	outfile << size<<endl;
	for (int z = 0;z < shapesList.size();z++) {
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
