#pragma once

#include "shape.h"

class Rpoly : public shape
{
private:
	Point center;
	Point vertex;
	int vertcies;
	int* x;
	int* y;
	double area=0;
public:
	Rpoly(Point Icenter, Point Ivertex, int Ivertices, GfxInfo shapeGfxInfo);
	Rpoly();
	virtual ~Rpoly();
	Point rotate_point(double cx, double cy, double angle, Point p);
	void set_x_y();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int)const;
	virtual void Save(ofstream& OutFile, int);
	double RpolygonArea(int X[], int Y[], int n)const;
	virtual void PrintInfo(GUI*) ;
<<<<<<< HEAD
	virtual void stickimages(GUI*u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
=======
	virtual void Load(string);
	void RotateShape();

>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
};


