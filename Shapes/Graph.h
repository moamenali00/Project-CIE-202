#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	int size = 0;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	shape* copied;
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) ;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void deSelect();
	void Hide();
<<<<<<< HEAD
	void StickI(GUI*G);
=======
	void StickI();
	void Rotate();
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
	void Save(ofstream& outfile);	//Save all shapes to a file
	void setColor(shape*);
	void Clear();
	void copy();
	void paste(GUI* G);
};
