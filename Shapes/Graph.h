#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include<stack>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	int size = 0;
	int id = 0;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	stack <shape*> redo;
	shape* copied;
public:			
	Graph();
	~Graph();
	void Redo(char);
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI)const ;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void deSelect();
	void Hide();
	void StickI(GUI*G);
	void Rotate();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void setColor(shape*);
	void Clear();
	void copy();
	void paste(GUI* G);
};
