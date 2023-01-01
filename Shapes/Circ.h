#pragma once

#include "shape.h"

class Circ : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Circ(Point, Point, GfxInfo shapeGfxInfo);
	Circ();
	virtual ~Circ();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;
	virtual void Save(ofstream& OutFile,int);
	virtual void PrintInfo(GUI*);
	virtual void Load(string);
	void RotateShape();
};


