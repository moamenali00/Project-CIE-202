#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

struct Trace {
	vector <int> Ids;
};

//A class that is responsible on everything related to shapes
class Graph
{
private:
	int size = 0;
	int id = 0;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	shape* copied;
	vector <Trace> undo;
	vector <Trace> redo;

public:			
	Graph();
	~Graph();
	void Undo(char);
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
	void paste(int x, int y);
	void scramble_image();
	void resize(float a);
};
