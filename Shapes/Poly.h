#pragma once

#include "shape.h"

class Poly : public shape
{
private:
	int* x;
	int* y;
	int vertcies;
public:
	Poly(int* Ix, int* Iy, int Ivertices, GfxInfo shapeGfxInfo);
	virtual ~Poly();
	virtual void Draw(GUI* pUI) const;
};


