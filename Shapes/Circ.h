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
<<<<<<< HEAD
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
=======
	virtual void Load(string);
	void RotateShape();
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
};


