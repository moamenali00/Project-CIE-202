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
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
	virtual void scramble();
	virtual void resize(float a);
	virtual void Move(int, int) ;
};


