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
	virtual ~Rpoly();
	Point rotate_point(double cx, double cy, double angle, Point p);
	void set_x_y();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int)const;
	virtual void Save(ofstream& OutFile, int);
	double RpolygonArea(int X[], int Y[], int n)const;
	virtual void PrintInfo(GUI*) ;

};


