#pragma once

#include"Shape.h"

class Poly : public shape
{
private:
	Point P1, P2, P3, P4, P5;
public:
	Poly(Point NP1, Point NP2, Point NP3, Point NP4, Point NP5, GfxInfo PolyGFxInfo);
	virtual ~Poly();
	virtual void Draw(GUI* pUI) const;
};

