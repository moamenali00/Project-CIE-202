#pragma once

#include "shape.h"

class Tri : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Tri(Point, Point,Point, GfxInfo shapeGfxInfo);
	Tri();
	virtual ~Tri();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;
	virtual void Save(ofstream& OutFile,int c);
	virtual void PrintInfo(GUI*);
<<<<<<< HEAD
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
=======
	virtual void Load(string) ;
	void RotateShape();
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
};



