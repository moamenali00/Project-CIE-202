#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

struct Trace {
	vector <int> Ids;
	double resize;
	Point I, F;
};

//A class that is responsible on everything related to shapes
class Graph
{
private:
	int size = 0;
	int id = 0;
	int match = 0;
	bool isMatch;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	vector<shape*> copied;
	vector <Trace> undo;
	vector <Trace> redo;

public:			
	Graph();
	~Graph();
	void Undo(char);
	void Redo(char);
	int getMatch();
	void setMatch(int);
	int getVisible();
	void set_isMatch(bool);
	bool get_isMatch();
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
	void duplicate_shape();
	void paste(int x, int y, int& n);
	void scramble_image();
	void resize(float a);
	void Move(Point);
	void Drag(shape*,Point, Point);
	void pHide(GUI* pGUI) const;
	void unHide(GUI*);
	void Restart();
	vector <shape*> get_selected();
	//int getHidden();
};
