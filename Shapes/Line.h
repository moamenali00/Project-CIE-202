#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	Line();
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;
	virtual void Save(ofstream& OutFile,int c);
	virtual void PrintInfo(GUI*);
	virtual void Load(string);
	Point rotate_point(double cx, double cy, double angle, Point p);

	void RotateShape();
	//Point rotate_pointL(double cx, double cy, double angle, Point p);
};


