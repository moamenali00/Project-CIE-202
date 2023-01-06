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
	virtual void Load(string);
	void RotateShape();
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
	Point rotate_point(double cx, double cy, double angle, Point p);
	virtual void scramble();
	virtual void resize(float a);
	virtual void Move(int, int);
	virtual shape* duplicate(GUI* pGUI);
	virtual void Hide(GUI* pGUI);

};
