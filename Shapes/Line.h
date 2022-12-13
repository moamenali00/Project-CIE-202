#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const { return 0; }

};


