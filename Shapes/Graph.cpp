#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
#include<iostream>

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
	pShp->setId(shapesList.size()-1);
	undo.push_back(Trace());
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsVisible())
		{
			shapePointer->Draw(pUI);
			if (shapePointer->iswithimage())
			{
				shapePointer->stickimages(pUI);
			}
		}
	}
}
void Graph::deSelect() {
	for (auto shapePointer : shapesList) {
		shapePointer->SetSelected(false);
	}
}
void Graph::StickI(GUI* G)
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->stickimages(G);
		}
	}
}
void Graph::copy()
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			copied = shapePointer->copy();
				return;
		}
	}
}
void Graph::paste(int x ,int y)
{
	
	copied->paste(x, y);
	shapesList.push_back(copied);
}

void Graph::scramble_image()
{
	
	for (auto shapePointer : shapesList) {
		shapePointer->scramble();
	}
	

	
	

}

void Graph::resize(float a)
{
	for (auto shapePointer : shapesList) 
	{
		if (shapePointer->IsSelected())
			shapePointer->resize(a);
	}
}

void Graph::setColor(shape* pShp) 
{
	GUI* pGUI;
	color clr = pGUI->getCrntFillColor();
	pShp->ChngFillClr(clr);
}
void Graph::Redo(char c) {
	if (c=='d'){
		for (auto ID : redo[redo.size() - 1].Ids) {
			shapesList[ID]->SetVisible(false);
		}
		undo.push_back(redo[redo.size() - 1]);
		redo.pop_back();
	}
}

void Graph::Undo(char c) {
	if (c == 'd') {
		for (auto ID : undo[undo.size()-1].Ids) {
			shapesList[ID]->SetVisible(true);
			}
		redo.push_back(undo[undo.size()-1]);
		undo.pop_back();
	}
}
void Graph::Hide() {
	undo.push_back(Trace());
	for (int i = 0;i < shapesList.size();i++) {
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->SetVisible(false);
			undo[undo.size() - 1].Ids.push_back(i);
		}
	}
	}


void Graph::Rotate() {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->RotateShape();
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
