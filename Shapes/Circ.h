#pragma once

#include "shape.h"

class Circ : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Circ(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circ();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;

};


