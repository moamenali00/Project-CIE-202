#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>
#include<iostream>
#include <chrono>
#include <thread>

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
	pShp->setId(id);
	undo.push_back(Trace());
	undo[undo.size() - 1].Ids.push_back(id++);
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	int i = 0;
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsVisible() && !shapePointer->isHide())
		{
			shapePointer->Draw(pUI);
			if (shapePointer->iswithimage())
			{
				shapePointer->stickimages(pUI);
			}
		}
		if (shapePointer->IsVisible() && shapePointer->isHide()) {
			shapePointer->Hide(pUI);
			if (shapePointer->IsSelected()&& !(pUI->getGUIMode())) {
				i++;
				
			}
			if (i == 1) { pUI->PrintMessage("1 shape is Selected"); }
			else if (i > 1) { pUI->PrintMessage(to_string(i) + " shape are selected"); };

		}
		}
	}
void Graph::unHide(GUI* pUI) {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected() && shapePointer->isHide()) {
			shapePointer->unHide(pUI);
			Draw(pUI);
			Sleep(500);
			shapePointer->Hide(pUI);
		}
	}
}
vector <shape*> Graph::get_selected() {
	vector <shape*> selectedShapes;
	for (int i =0;i< shapesList.size();i++)
	{
		if (shapesList[i]->IsSelected()) {
			selectedShapes.push_back(shapesList[i]);
		}
	}
	return selectedShapes;
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
void Graph::pHide(GUI* pGUI) const {
	for (auto shapePointer : shapesList) {
		shapePointer->Hide(pGUI);
	}
}

void Graph::copy()
{
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) 
		{
			copied.push_back(shapePointer->copy());
		}
	}
}
void Graph::paste(int x ,int y,int& n)
{
	if (copied.size() == 0)
	{
		n = 0; return;
	}
	copied.back()->paste(x, y);
	shapesList.push_back(copied.back());
	copied.pop_back();
	n = copied.size();
}

void Graph::scramble_image()
{
	for (auto shapePointer : shapesList) {
		shapePointer->scramble();
	}
}

void Graph::resize(float a)
{
	undo.push_back(Trace());
	undo[undo.size() - 1].resize = a;
	for(int i=0;i<shapesList.size();i++)
	{
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->resize(a);
			undo[undo.size() - 1].Ids.push_back(i);
		}
			
	}
}
void Graph::Move(Point D) {
	for (auto shapePointer : shapesList) {
		if (shapePointer->IsSelected()) {
			shapePointer->Move(D.x, D.y);
		}
	}
}
void Graph::Drag(shape* S,Point I, Point F) {
	undo.push_back(Trace());
	undo[undo.size() - 1].Ids.push_back(S->getId());
	undo[undo.size() - 1].I = I;undo[undo.size() - 1].F = F;

	
}
void Graph::setColor(shape* pShp) 
{
	GUI* pGUI;
	color clr = pGUI->getCrntFillColor();
	pShp->ChngFillClr(clr);
}
void Graph::Redo(char c) {
	if (c == 'd') {
		for (auto ID : redo[redo.size() - 1].Ids) {
			shapesList[ID]->SetVisible(false);
		}
		undo.push_back(redo[redo.size() - 1]);
		redo.pop_back();
	}
	else if (c == 's') {
		for (auto ID : redo[redo.size() - 1].Ids) {
			shapesList[ID]->resize(redo[redo.size() - 1].resize);
		}
		undo.push_back(redo[redo.size() - 1]);
		redo.pop_back();
	}
	else if (c == 'f') {
		for (auto ID : redo[redo.size() - 1].Ids) {
			double diffx = redo[redo.size() - 1].F.x - redo[redo.size() - 1].I.x;
			double diffy = redo[redo.size() - 1].F.y - redo[redo.size() - 1].I.y;
			shapesList[ID]->Move(diffx, diffy);
		}
		undo.push_back(redo[redo.size() - 1]);
		redo.pop_back();
	}
	else if (c == 'c') {
		shapesList[redo[redo.size() - 1].Ids[0]]->SetVisible(true);
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
	else if (c == 's') {
		for (auto ID : undo[undo.size() - 1].Ids) {
			shapesList[ID]->resize(pow(undo[undo.size()-1].resize, -1));
		}
		redo.push_back(undo[undo.size() - 1]);
		undo.pop_back();
	}
	else if (c == 'f') {
		for (auto ID : undo[undo.size() - 1].Ids) {
			double diffx = undo[undo.size() - 1].I.x - undo[undo.size() - 1].F.x;
			double diffy = undo[undo.size() - 1].I.y - undo[undo.size() - 1].F.y;
			shapesList[ID]->Move(diffx,diffy);
		}
		redo.push_back(undo[undo.size() - 1]);
		undo.pop_back();
	}
	else if (c == 'c') {
		shapesList[undo[undo.size() - 1].Ids[0]]->SetVisible(false);
		redo.push_back(undo[undo.size() - 1]);
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

void Graph::duplicate_shape(GUI* pGUI)
{	
	size = shapesList.size();

	for (int i = 0; i < size;i++) {
			
		shapesList.push_back(shapesList[i]->duplicate(pGUI));
	}
}