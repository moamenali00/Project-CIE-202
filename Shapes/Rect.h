#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	Rect();
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;
	virtual void Save(ofstream& OutFile,int c);
	virtual void PrintInfo(GUI*);
<<<<<<< HEAD
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
=======
	virtual void Load(string);
	void RotateShape();
	Point rotate_point(double cx, double cy, double angle, Point p);
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
};

